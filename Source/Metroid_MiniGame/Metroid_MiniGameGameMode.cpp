// Copyright Epic Games, Inc. All Rights Reserved.

#include "Metroid_MiniGameGameMode.h"
#include "Metroid_MiniGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMetroid_MiniGameGameMode::AMetroid_MiniGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
