// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Sound/SoundBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MAIDENSOFSTEEL_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(Category = Game, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UTriggerComponent * TriggerComponent;

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	/* The speed our ship moves around the level */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MoveSpeed;

	// HP at game start
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float MaxHP;

	// HP at current moment
	UPROPERTY(Category = Gameplay, VisibleAnywhere, BlueprintReadOnly)
	float CurrentHP;

	FVector DesiredVelocity;

	/** Sound to play each time we fire */
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// Begin Actor Interface
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End Actor Interface

	/* Fire a shot in the specified direction */
	void FireShotPress();
	void FireShotRelease();

	// Damages the player, reducing their currentHP
	void TakeDamage();
	void TakeDamage(float damageValue);

	// Switch the player
	void SwitchPlayer();

	/* Handler for the fire timer expiry */
	void ShotTimerExpired();

	void MoveForward(float ForwardValue);
	void MoveRight(float RightValue);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ASwitchController* PlayerCon;

	/* Flag to control firing  */
	uint32 bCanFire : 1;

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;
};
