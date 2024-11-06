// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartupData/DataAsset_HeroStartupData.h"
#include "AbilitySystem/Abilities/ARPGGameplayAbility.h"
#include "AbilitySystem/ARPGAbilitySystemComponent.h"

void UDataAsset_HeroStartupData::GiveToAbilitySystemComponent(UARPGAbilitySystemComponent* ASCToGive, int32 ApplyLevel)
{
    Super::GiveToAbilitySystemComponent(ASCToGive, ApplyLevel);

    for (const FARPGHeroAbilitySet& AbilitySet : HeroStartupAbilitySets)
    {
        if (!AbilitySet.IsValid())
        {
            continue;
        }

        FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
        AbilitySpec.SourceObject = ASCToGive->GetAvatarActor();
        AbilitySpec.Level = ApplyLevel;
        AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

        ASCToGive->GiveAbility(AbilitySpec);
    }
}
