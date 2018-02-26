// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();

	auto TankPrimitive = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankPrimitive->AddForceAtLocation(ForceApplied, ForceLocation);
}

