// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class CREATORTEMPLATE_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite)
	int CurrentHead;

	UPROPERTY(BlueprintReadWrite)
	int CurrentTorso;

	UPROPERTY(BlueprintReadWrite)
	int CurrentLegs;

	UPROPERTY(BlueprintReadWrite)
	int CurrentFeet;
};
