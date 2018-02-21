// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float ReletiveSpeed)
{
	ReletiveSpeed = FMath::Clamp<float>(ReletiveSpeed, -1, 1);

	auto RotationOffset = ReletiveSpeed * MaxDergeesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RotationNew = FMath::Clamp(RelativeRotation.Pitch + RotationOffset, MinElevationDegress, MaxElevationDegress);

	SetRelativeRotation(FRotator(RotationNew, 0, 0));
}

