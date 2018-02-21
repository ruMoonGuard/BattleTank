// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

#include "Engine/World.h"

void UTankTurret::Rotation(float ReletiveSpeed)
{
	ReletiveSpeed = FMath::Clamp(ReletiveSpeed, -1.0f, 1.0f);

	auto RotationOffset = ReletiveSpeed * MaxDergeesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RotationNew = RelativeRotation.Yaw + RotationOffset;

	SetRelativeRotation(FRotator(0, RotationNew, 0));
}

