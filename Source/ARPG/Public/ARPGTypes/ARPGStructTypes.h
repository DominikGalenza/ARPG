// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ARPGStructTypes.generated.h"

class UARPGHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FARPGHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UARPGHeroLinkedAnimLayer> WeaponAnimLayerToLink;

};