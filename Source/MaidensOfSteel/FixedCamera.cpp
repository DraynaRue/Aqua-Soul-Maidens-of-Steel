// Fill out your copyright notice in the Description page of Project Settings.

#include "FixedCamera.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFixedCamera::AFixedCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	RootComponent = CameraComponent;
}

void AFixedCamera::SetPlayerCamera()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTargetWithBlend(this);
}

// Called when the game starts or when spawned
void AFixedCamera::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFixedCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFixedCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

