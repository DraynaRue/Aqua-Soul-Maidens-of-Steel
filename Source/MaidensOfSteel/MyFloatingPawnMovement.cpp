// Fill out your copyright notice in the Description page of Project Settings.

#include "MyFloatingPawnMovement.h"

void UMyFloatingPawnMovement::ApplyInput(float ForwardValue, float RightValue, float DeltaSeconds)
{
	AddInputVector(GetOwner()->GetActorForwardVector() * ForwardValue);

	// get the current rotation
	FRotator rot = GetOwner()->GetActorRotation();

	// if we have some left/right input value.. then rotate
	if (FMath::Abs(RightValue) > 0.001f) rot.Add(0.0f, RightValue * RotateSpeed * DeltaSeconds, 0.0f);
	GetOwner()->SetActorRotation(rot);
}
