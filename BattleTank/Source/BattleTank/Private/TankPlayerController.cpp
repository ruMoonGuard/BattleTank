// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* tank = GetControlledTank();

	UE_LOG(LogTemp, Warning, TEXT("%s found component"), *(tank->GetName()));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 SizeX, SizeY;
	GetViewportSize(OUT SizeX, OUT SizeY);

	auto ScreenLocation = FVector2D(SizeX * CrossHairXLocation, SizeY * CrossHairYLocation);

	FVector WorldLocation, WorldDirection;

	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT WorldLocation, OUT WorldDirection))
	{
		return GetLookVectorHitLocation(WorldDirection, OUT HitLocation);
	}

	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	
	HitLocation = FVector(0);
	return false;
}
