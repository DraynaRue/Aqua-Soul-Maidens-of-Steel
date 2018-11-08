// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerGameMode.h"
#include "PlayerCharacter.h"

APlayerGameMode::APlayerGameMode() 
{
	// set default pawn class to our character class
	DefaultPawnClass = APlayerCharacter::StaticClass();
}
