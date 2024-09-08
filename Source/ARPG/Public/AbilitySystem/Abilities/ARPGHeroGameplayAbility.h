// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/ARPGGameplayAbility.h"
#include "ARPGHeroGameplayAbility.generated.h"

class AARPGHeroCharacter;
class AARPGHeroController;

/**
 * 
 */
UCLASS()
class ARPG_API UARPGHeroGameplayAbility : public UARPGGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "ARPGAbility")
	AARPGHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "ARPGAbility")
	AARPGHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "ARPGAbility")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AARPGHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AARPGHeroController> CachedHeroController;
};
