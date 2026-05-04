// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "MySaveGame.h"
#include <Kismet/GameplayStatics.h>

void UMyBlueprintFunctionLibrary::SaveCharacterChoices(int Head, int Torso, int Legs, int Feet)
{
	UMySaveGame* CharacterSaveData = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	CharacterSaveData->CurrentHead = Head;
	CharacterSaveData->CurrentTorso = Torso;
	CharacterSaveData->CurrentLegs = Legs;
	CharacterSaveData->CurrentFeet = Feet;

	UGameplayStatics::AsyncSaveGameToSlot(CharacterSaveData, TEXT("CharacterChoices"), 0); // Save using Async because it's good practice and the reccomended method.
}

void UMyBlueprintFunctionLibrary::LoadCharacterChoices(int& Head, int& Torso, int& Legs, int& Feet)
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("CharacterChoices"), 0))
	{
		UMySaveGame* CharacterSaveData = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("CharacterChoices"), 0));
		Head = CharacterSaveData->CurrentHead;
		Torso = CharacterSaveData->CurrentTorso;
		Legs = CharacterSaveData->CurrentLegs;
		Feet = CharacterSaveData->CurrentFeet;
	}
	else
	{
		return;
	}
}

// https://dev.epicgames.com/documentation/unreal-engine/saving-and-loading-your-game-in-unreal-engine I used the information available on unreal's website to help create this.
