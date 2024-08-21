// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AARPGWeaponBase;

/**
 * 
 */
UCLASS()
class ARPG_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, AARPGWeaponBase* WeaponToRegister, bool bRegisterAsEquippedWeapon = false);
	
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AARPGWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag WeaponTagToGet) const;

	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AARPGWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

private:
	TMap<FGameplayTag, AARPGWeaponBase*> CharacterCarriedWeaponMap;
};
