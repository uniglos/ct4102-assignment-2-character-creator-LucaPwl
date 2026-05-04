// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CREATORTEMPLATE_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static void SaveCharacterChoices(int Head, int Torso, int Legs, int Feet);

	UFUNCTION(BlueprintCallable)
	static void LoadCharacterChoices(int& Head, int& Torso, int& Legs, int& Feet);
};
