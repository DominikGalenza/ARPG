// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "Items/Weapons/ARPGWeaponBase.h"
#include "ARPGDebugHelper.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag WeaponTagToRegister, AARPGWeaponBase* WeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(WeaponTagToRegister), TEXT("A tag named %s has already been as carried weapon"), *WeaponTagToRegister.ToString());
	check(WeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(WeaponTagToRegister, WeaponToRegister);
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = WeaponTagToRegister;
	}

	const FString WeaponString = FString::Printf(TEXT("A weapone named: %s has been registered using the tag %s"), *WeaponToRegister->GetName(), *WeaponTagToRegister.ToString());
	Debug::Print(WeaponString);
}

AARPGWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag WeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(WeaponTagToGet))
	{
		if (AARPGWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(WeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}

	return nullptr;
}

AARPGWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
