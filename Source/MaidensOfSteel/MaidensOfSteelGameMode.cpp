// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "MaidensOfSteelGameMode.h"
#include "MaidensOfSteelPawn.h"

AMaidensOfSteelGameMode::AMaidensOfSteelGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AMaidensOfSteelPawn::StaticClass();
}

