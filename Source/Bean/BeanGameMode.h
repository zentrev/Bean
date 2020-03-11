// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BeanGameMode.generated.h"

UCLASS(minimalapi)
class ABeanGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABeanGameMode();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Books")
		int BooksToCollect = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Books")
		int Books = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Books")
		FName WinLevel = "EndMenu";
public:
	UFUNCTION(BlueprintCallable, Category = "Books")
		void AddBook();
};



