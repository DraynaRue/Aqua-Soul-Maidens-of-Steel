// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
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


// Sets default values
APlayerPawn::APlayerPawn()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	TriggerComponent = CreateDefaultSubobject<UTriggerComponent>(TEXT("TriggerCompenent"));

	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	TriggerComponent->FireRate = FireRate;

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up action bindings

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerPawn::FireShotPress);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &APlayerPawn::FireShotRelease);

	// set up axis bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);
}

// Called every frame
void APlayerPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayerPawn::FireShotPress()
{
	TriggerComponent->doFire = true;
}

void APlayerPawn::FireShotRelease()
{
	TriggerComponent->doFire = false;
}

void APlayerPawn::ShotTimerExpired()
{
	bCanFire = true;
}

void APlayerPawn::MoveForward(float ForwardValue)
{
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("%f"),ForwardValue));
	AddMovementInput(GetActorForwardVector() * ForwardValue, MoveSpeed);
}

void APlayerPawn::MoveRight(float RightValue)
{
	AddMovementInput(GetActorRightVector() * RightValue, MoveSpeed);
}
