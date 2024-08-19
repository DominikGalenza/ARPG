// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartupDatabase.generated.h"

class UARPGGameplayAbility;
class UARPGAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class ARPG_API UDataAsset_StartupDatabase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UARPGAbilitySystemComponent* ASCToGive, int32 ApplyLevel = 1);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UARPGGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartupData")
	TArray<TSubclassOf<UARPGGameplayAbility>> ReactiveAbilities;

	void GrantAbilites(const TArray<TSubclassOf<UARPGGameplayAbility>>& AbilitiesToGive, UARPGAbilitySystemComponent* ASCToGive, int32 ApplyLevel = 1);
};
