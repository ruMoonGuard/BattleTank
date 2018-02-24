// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto Tank = Cast<ATank>(GetPawn());

	if (!Tank) { return; }

	if (PlayerTank)
	{
		// TODO move to player

		// Aim towards the player
		Tank->AimAt(PlayerTank->GetActorLocation());

		Tank->Fire();
	}
	
}