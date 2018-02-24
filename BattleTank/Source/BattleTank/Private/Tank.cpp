// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "Tank.h"
#include "TankAimingComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>("Aiming_Component");
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (TankAimingComponent)
	{
		TankAimingComponent->SetBarrelReference(BarrelToSet);
	}

	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	if (TankAimingComponent)
	{
		TankAimingComponent->SetTurretReference(TurretToSet);
	}
}


void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!Projectile || !Barrel) { return; }

	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{
		auto SpawnLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto SpawnRotation = Barrel->GetSocketRotation(FName("Projectile"));

		auto SpawnProjectile = GetWorld()->SpawnActor<AProjectile>(Projectile, SpawnLocation, SpawnRotation);

		if (SpawnProjectile)
		{
			SpawnProjectile->LaunchProjectile(LaunchSpeed);

			LastFireTime = FPlatformTime::Seconds();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Pawn: %s received error when spawn"), *GetName());
		}
	}
}