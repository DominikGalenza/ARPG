// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartupData/DataAsset_StartupDatabase.h"
#include "AbilitySystem/ARPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/ARPGGameplayAbility.h"

void UDataAsset_StartupDatabase::GiveToAbilitySystemComponent(UARPGAbilitySystemComponent* ASCToGive, int32 ApplyLevel)
{
	check(ASCToGive);

	GrantAbilites(ActivateOnGivenAbilities, ASCToGive, ApplyLevel);
	GrantAbilites(ReactiveAbilities, ASCToGive, ApplyLevel);
}

void UDataAsset_StartupDatabase::GrantAbilites(const TArray<TSubclassOf<UARPGGameplayAbility>>& AbilitiesToGive, UARPGAbilitySystemComponent* ASCToGive, int32 ApplyLevel)
{
	if (AbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<UARPGGameplayAbility>& Ability : AbilitiesToGive)
	{
		if (!Ability)
		{
			continue;
		}

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = ASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;

		ASCToGive->GiveAbility(AbilitySpec);
	}
}
