// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "BeanGameMode.h"
#include "BeanCharacter.h"
#include "Kismet/GameplayStatics.h"

#include "UObject/ConstructorHelpers.h"

ABeanGameMode::ABeanGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_BeanCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("It's Null fool"));
	}
}

void ABeanGameMode::AddBook()
{
	Books++;
	if (Books >= BooksToCollect && WinLevel != "")
	{
		FLatentActionInfo LatentInfo;
		UGameplayStatics::LoadStreamLevel(this, WinLevel, true, true, LatentInfo);
	}
}
