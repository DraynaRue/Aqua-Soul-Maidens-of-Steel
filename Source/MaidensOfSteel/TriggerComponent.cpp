// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (bCanTrigger)
	{
		// and send even to things that can be triggered (I'm thinking weapons/buffs whatever)
		OnTriggered.Broadcast(doFire);

		// disable this trigger tick code until timer says we can fire again
		bCanTrigger = false;

		// kick off a timer based on timer handle and firing rate
		GetWorld()->GetTimerManager().SetTimer(TimerHandle_TriggerTimerExpired, this, &UTriggerComponent::TriggerTimeExpired, FireRate);
	}
}

// Called when the game ends playing
void UTriggerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	// ...
	OnTriggered.Clear();
}

void UTriggerComponent::TriggerTimeExpired()
{
	bCanTrigger = true;
}