// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downnward speed, and +1 is max up movement
	void Elevate(float ReletiveSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDergeesPerSecond = 5;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegress = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegress = 0;
};
