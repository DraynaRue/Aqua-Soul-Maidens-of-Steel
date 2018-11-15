// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemySpawner.h"
#include "Engine/World.h"
#include "EnemyCharacter.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UWorld* const World = GetWorld();
	if (bCanSpawn)
	{
		// spawn the enemy
		FActorSpawnParameters params;
		params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		params.bNoFail = true;
		params.Owner = GetOwner();
		params.Instigator = Cast<APawn>(GetOwner());


		AEnemyCharacter* spawnedactor = World->SpawnActor<AEnemyCharacter>(EnemyType, SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation(), params);
		if (spawnedactor != nullptr)
		{
			spawnedactor->AddMovementInput(spawnedactor->GetActorRightVector(), 1);
			GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Spawn!!"));
		}

		bCanSpawn = false;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_SpawnTimerExpired, this, &AEnemySpawner::SpawnTimerExpired, SpawnRate);
	}
}

void AEnemySpawner::SpawnTimerExpired()
{
	bCanSpawn = true;
}

