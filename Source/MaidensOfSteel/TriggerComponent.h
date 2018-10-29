// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TriggerComponent.generated.h"

// declare event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTriggerEvent, bool, doFire);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAIDENSOFSTEEL_API UTriggerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTriggerComponent();

	// input vector
	bool doFire;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	bool TriggersOnNonZeroVector = true;

	// Broadcasts whenever the trigger is triggered
	// event declaration
	UPROPERTY(BlueprintAssignable, Category = "TriggerState")
	FTriggerEvent OnTriggered;

	// Flag to control firing
	bool bCanTrigger = true;

	// Handle for efficient management of ShotTimerExpired timer
	FTimerHandle TimerHandle_TriggerTimerExpired;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void TriggerTimeExpired();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
