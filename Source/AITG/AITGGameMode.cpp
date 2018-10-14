// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "AITGGameMode.h"
#include "AITGHUD.h"
#include "AITGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAITGGameMode::AAITGGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AAITGHUD::StaticClass();
}
