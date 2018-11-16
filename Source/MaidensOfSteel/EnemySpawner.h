// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"
#include "EnemySpawner.generated.h"

UCLASS()
class MAIDENSOFSTEEL_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float SpawnRate;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AEnemyCharacter> EnemyType;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	AActor* SpawnPoint;

	// Flag to control spawning
	bool bCanSpawn = true;

	FTimerHandle TimerHandle_SpawnTimerExpired;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnTimerExpired();
	
};
