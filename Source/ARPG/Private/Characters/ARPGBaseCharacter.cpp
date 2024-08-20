// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ARPGBaseCharacter.h"
#include "AbilitySystem/ARPGAbilitySystemComponent.h"
#include "AbilitySystem/ARPGAttributeSet.h"

// Sets default values
AARPGBaseCharacter::AARPGBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	ARPGAbilitySystemComponent = CreateDefaultSubobject<UARPGAbilitySystemComponent>(TEXT("ARPGAbilitySystemComponent"));
	ARPGAttributeSet = CreateDefaultSubobject<UARPGAttributeSet>(TEXT("ARPGAttributeSet"));
}

UAbilitySystemComponent* AARPGBaseCharacter::GetAbilitySystemComponent() const
{
	return GetARPGAbilitySystemComponent();
}

void AARPGBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (ARPGAbilitySystemComponent)
	{
		ARPGAbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensureMsgf(!CharacterStartupData.IsNull(), TEXT("Forgot to assign start-up data to %s"), *GetName());
	}
}
