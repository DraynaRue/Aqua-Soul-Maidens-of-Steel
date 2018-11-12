// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "MaidensOfSteelProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "TriggerComponent.h"
#include "SwitchController.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
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

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	// Set current HP to the maximum set in the blueprint
	CurrentHP = MaxHP;

	ASwitchController* controller = Cast<ASwitchController>(GetWorld()->GetFirstPlayerController());
	controller->AddPlayerToList(this);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	// set up action bindings

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::FireShotPress);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerCharacter::FireShotRelease);
	PlayerInputComponent->BindAction("Damage", IE_Pressed, this, &APlayerCharacter::TakeDamage);
	PlayerInputComponent->BindAction("Switch", IE_Pressed, this, &APlayerCharacter::SwitchPlayer);
	
	// set up axis bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

}

void APlayerCharacter::FireShotPress()
{
	TriggerComponent->doFire = true;
}

void APlayerCharacter::FireShotRelease()
{
	TriggerComponent->doFire = false;
}

void APlayerCharacter::TakeDamage()
{
	if (CurrentHP > 0)
	{
		CurrentHP--;

		if (CurrentHP <= 0)
		{
			UGameplayStatics::OpenLevel(GetWorld(), "GameOverMap");
		}
	}
}

void APlayerCharacter::SwitchPlayer()
{
}

void APlayerCharacter::ShotTimerExpired()
{
	bCanFire = true;
}

void APlayerCharacter::MoveForward(float ForwardValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("%f"), ForwardValue));
	if (ForwardValue != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), ForwardValue);
	}
}

void APlayerCharacter::MoveRight(float RightValue)
{
	if (RightValue != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), RightValue);
	}
}