// Copyright Epic Games, Inc. All Rights Reserved.

#include "platformer3d_cppGameMode.h"
#include "platformer3d_cppCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aplatformer3d_cppGameMode::Aplatformer3d_cppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Myplatformer3d_cppCharacter"));
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
