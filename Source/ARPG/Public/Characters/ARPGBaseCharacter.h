// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ARPGBaseCharacter.generated.h"

class UARPGAbilitySystemComponent;
class UARPGAttributeSet;
class UDataAsset_StartupDatabase;

UCLASS()
class ARPG_API AARPGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AARPGBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

	FORCEINLINE UARPGAbilitySystemComponent* GetARPGAbilitySystemComponent() const { return ARPGAbilitySystemComponent; }
	FORCEINLINE UARPGAttributeSet* GetARPGAttributeSet() const { return ARPGAttributeSet; }
protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UARPGAbilitySystemComponent* ARPGAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UARPGAttributeSet* ARPGAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartupDatabase> CharacterStartupData;
};
