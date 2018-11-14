// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TriggerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NormalProjectile.h"
#include "TriggerableWeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAIDENSOFSTEEL_API UTriggerableWeaponComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTriggerableWeaponComponent();

	// what type of projectile does this triggerbale weapon fire
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ANormalProjectile> ProjectileType;

	// Sound to play each time we fire
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;

	// this has to be a ufunction so that it can be bound to the OnTriggered multicast delegate on the trigger component
	UFUNCTION()
	void Triggered(bool doFire);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};
