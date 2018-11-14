// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerableWeaponComponent.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTriggerableWeaponComponent::UTriggerableWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTriggerableWeaponComponent::Triggered(bool doFire)
{
	UWorld* const World = GetWorld();
	if (World != NULL && ProjectileType != nullptr)
	{
		if (doFire == true)
		{
			// spawn the projectile
			FActorSpawnParameters params;
			params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			params.bNoFail = true;
			params.Owner = GetOwner();
			params.Instigator = Cast<APawn>(GetOwner());


			ANormalProjectile* spawnedactor = World->SpawnActor<ANormalProjectile>(ProjectileType, GetComponentLocation(), GetComponentRotation(), params);
			if (spawnedactor != nullptr)
			{
				// try and play the sound of specified
				if (FireSound != nullptr)
				{
					UGameplayStatics::PlaySoundAtLocation(GetOwner(), FireSound, GetComponentLocation());
				}
			}
		}
	}
}

// Called when the game starts
void UTriggerableWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UTriggerComponent * TriggerPtr = GetOwner()->FindComponentByClass<UTriggerComponent>();
	if (TriggerPtr)
	{
		// get the trigger delegate and add this triggerable to its triggered event
		TriggerPtr->OnTriggered.AddDynamic(this, &UTriggerableWeaponComponent::Triggered);
	}
}


// Called every frame
void UTriggerableWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

