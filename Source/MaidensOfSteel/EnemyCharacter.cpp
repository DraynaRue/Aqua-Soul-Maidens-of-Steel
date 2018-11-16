// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "TriggerComponent.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerComponent = CreateDefaultSubobject<UTriggerComponent>(TEXT("TriggerCompenent"));
	TriggerComponent->FireRate = FireRate;

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

}

void AEnemyCharacter::TakeDamage()
{
	if (CurrentHP > 0)
	{
		CurrentHP--;

		if (CurrentHP <= 0)
		{
			Destroy();
		}
	}
}

void AEnemyCharacter::TakeDamage(float damageValue)
{
	if (CurrentHP > 0)
	{
		CurrentHP = CurrentHP - damageValue;

		if (CurrentHP <= 0)
		{
			Destroy();
		}
	}
}

void AEnemyCharacter::ShotTimerExpired()
{
	bCanFire = true;
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Set current HP to the maximum set in the blueprint
	CurrentHP = MaxHP;
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector EnemyMov = FVector(0, -1, 0);
	SetActorLocation(GetActorLocation() + EnemyMov);

	TriggerComponent->doFire = true;
}

