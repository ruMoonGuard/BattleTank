// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto player = GetPlayerController();

	if (player)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: %s found player pawn %s"), *GetName(), *(player->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController: %s can't found player pawn"), *GetName());
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetControlledTank()) { return; }

	if (GetPlayerController())
	{
		// TODO move to player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerController()->GetActorLocation());

		// TODO fire if ready
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerController() const
{
	auto player = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!player)
	{
		return nullptr;
	}

	return Cast<ATank>(player);
}