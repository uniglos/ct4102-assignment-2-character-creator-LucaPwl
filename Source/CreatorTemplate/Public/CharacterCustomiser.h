// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/SkeletalMesh.h"
#include "GameFramework/Character.h"
#include "CharacterCustomiser.generated.h"


UENUM(BlueprintType)
enum class ECurrentBodyPart : uint8
{
	Head,
	Torso,
	Legs,
	Feet
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CREATORTEMPLATE_API UCharacterCustomiser : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterCustomiser();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SelectNextPart();

	UFUNCTION(BlueprintCallable)
	void SelectPreviousPart();
private:
	class ACharacter* Character;
	UPROPERTY(EditAnywhere)
	TArray<USkeletalMesh*> HeadParts;

	UPROPERTY(EditAnywhere)
	TArray<USkeletalMesh*> TorsoParts;

	UPROPERTY(EditAnywhere)
	TArray<USkeletalMesh*> LegParts;

	UPROPERTY(EditAnywhere)
	TArray<USkeletalMesh*> FeetParts;

	ECurrentBodyPart CurrentPart;
};
