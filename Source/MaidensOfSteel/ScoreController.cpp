// Fill out your copyright notice in the Description page of Project Settings.

#include "ScoreController.h"

float AScoreController::PlayerScore;

// Sets default values
AScoreController::AScoreController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreController::BeginPlay()
{
	Super::BeginPlay();
	SetPlayerScore(0);
}

// Called every frame
void AScoreController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Score = GetPlayerScore();
}

float AScoreController::GetPlayerScore()
{
	return PlayerScore;
}

void AScoreController::SetPlayerScore(float Score)
{
	PlayerScore = Score;
}

void AScoreController::AddPlayerScore(float ScoreToAdd)
{
	PlayerScore = PlayerScore + ScoreToAdd;
}

