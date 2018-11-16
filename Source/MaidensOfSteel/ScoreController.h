// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreController.generated.h"

UCLASS()
class MAIDENSOFSTEEL_API AScoreController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreController();

	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadOnly)
	float Score;

	static float GetPlayerScore();
	static void SetPlayerScore(float Score);
	static void AddPlayerScore(float ScoreToAdd);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	static float PlayerScore;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
