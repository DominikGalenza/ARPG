// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ARPGHeroCharacter.h"

#include "ARPGDebugHelper.h"

void AARPGHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
