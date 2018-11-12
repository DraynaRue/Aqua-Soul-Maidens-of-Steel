// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PlayerCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SwitchController.generated.h"

UCLASS()
class MAIDENSOFSTEEL_API ASwitchController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASwitchController();

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent);

	//Add player to list of switchable characters
	void AddPlayerToList(APlayerCharacter* PlayerToAdd);
	void SwitchPlayer();
	
protected:
	TArray<APawn*> PlayerList;

};
