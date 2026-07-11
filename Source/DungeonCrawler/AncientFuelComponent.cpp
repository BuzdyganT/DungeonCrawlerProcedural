// Fill out your copyright notice in the Description page of Project Settings.


#include "AncientFuelComponent.h"
#include "TimerManager.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UAncientFuelComponent::UAncientFuelComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAncientFuelComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentFuel = MaxFuel;
	
	// Odpala funkcję DrainFuel co 1 sekundę w pętli (true)
	GetWorld()->GetTimerManager().SetTimer(FuelTimerHandle, this, &UAncientFuelComponent::DrainFuel, 1.0f, true);
	// ...
	
}


// Called every frame
void UAncientFuelComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UAncientFuelComponent::DrainFuel()
{
	CurrentFuel -= DrainRate;
	
	UE_LOG(LogTemp, Warning, TEXT("Paliwo: %f"), CurrentFuel);

	if (CurrentFuel <= 0.0f)
	{
		CurrentFuel = 0.0f;
		UE_LOG(LogTemp, Error, TEXT("Koniec paliwa! Czas na teleport."));
		GetWorld()->GetTimerManager().ClearTimer(FuelTimerHandle); 
	}
}

