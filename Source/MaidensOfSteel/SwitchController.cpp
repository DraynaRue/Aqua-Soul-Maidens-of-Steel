// Fill out your copyright notice in the Description page of Project Settings.

#include "SwitchController.h"

ASwitchController::ASwitchController()
{
}

void ASwitchController::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
}

void ASwitchController::AddPlayerToList(APlayerCharacter* PlayerToAdd)
{
	PlayerList.Add(PlayerToAdd);
}

void ASwitchController::SwitchPlayer()
{
}
