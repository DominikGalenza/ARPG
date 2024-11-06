// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPGTypes/ARPGStructTypes.h"
#include "AbilitySystem/Abilities/ARPGGameplayAbility.h"

bool FARPGHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}