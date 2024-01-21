// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearningLostArkGameMode.h"
#include "LearningLostArkPlayerController.h"
#include "LearningLostArkCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearningLostArkGameMode::ALearningLostArkGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ALearningLostArkPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}