// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartupData/DataAsset_StartupDatabase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_HeroStartupData.generated.h"

USTRUCT(BlueprintType)
struct FARPGHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UARPGGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};
/**
 * 
 */
UCLASS()
class ARPG_API UDataAsset_HeroStartupData : public UDataAsset_StartupDatabase
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UARPGAbilitySystemComponent* ASCToGive, int32 ApplyLevel = 1) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartupData", meta = (TitleProperty = "InputTag"))
	TArray<FARPGHeroAbilitySet> HeroStartupAbilitySets;
};
