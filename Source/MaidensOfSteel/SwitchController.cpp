// Fill out your copyright notice in the Description page of Project Settings.

#include "SwitchController.h"
#include "FixedCamera.h"
#include "Kismet/GameplayStatics.h"

ASwitchController::ASwitchController()
{
}

void ASwitchController::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
}
/*
void ASwitchController::AddPlayerToList(APlayerCharacter* PlayerToAdd)
{
	PlayerList.Add(PlayerToAdd);
}
*/
void ASwitchController::SwitchPlayer()
{
	if (isPlayer1)
	{
		FVector P1Pos;
		P1Pos = Player1->GetActorLocation();

		UnPossess();
		Player1->SetActorLocation(Player2->GetActorLocation());
		Player2->SetActorLocation(P1Pos);
		Possess(Player2);

		AFixedCamera::SetPlayerCamera();

		isPlayer1 = false;
	}
	else if (!isPlayer1)
	{
		FVector P2Pos;
		P2Pos = Player2->GetActorLocation();

		UnPossess();
		Player2->SetActorLocation(Player1->GetActorLocation());
		Player1->SetActorLocation(P2Pos);
		Possess(Player1);

		AFixedCamera::SetPlayerCamera();

		isPlayer1 = true;
	}

}

void ASwitchController::BeginPlay()
{
	isPlayer1 = true;

	for (TActorIterator<APlayerCharacter> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{ 
		if (ActorItr->ActorHasTag(TEXT("Player1")))
		{
			APlayerCharacter* Mesh = *ActorItr;
			Player1 = Mesh;
		}
		else if (ActorItr->ActorHasTag(TEXT("Player2")))
		{
			APlayerCharacter* Mesh = *ActorItr;
			Player2 = Mesh;
		}
	}
}
