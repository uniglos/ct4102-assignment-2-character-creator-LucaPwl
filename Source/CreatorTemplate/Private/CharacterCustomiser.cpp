// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterCustomiser.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UCharacterCustomiser::UCharacterCustomiser()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterCustomiser::BeginPlay()
{
	Super::BeginPlay();
	Character = Cast<ACharacter>(GetOwner());
	// ...
}


// Called every frame
void UCharacterCustomiser::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCharacterCustomiser::SelectNextPart()
{
	int32 Value = static_cast<int32>(CurrentPart);
	Value = (Value + 1) % 4;
	CurrentPart = static_cast<ECurrentBodyPart>(Value);
}

void UCharacterCustomiser::SelectPreviousPart()
{
	int32 Value = static_cast<int32>(CurrentPart);
	Value--;
	if (Value < 0)
	{
		Value = 3;
	}
	CurrentPart = static_cast<ECurrentBodyPart>(Value);
}

