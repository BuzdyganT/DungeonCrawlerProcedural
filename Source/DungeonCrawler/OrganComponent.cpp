// Fill out your copyright notice in the Description page of Project Settings.


#include "OrganComponent.h"

// Sets default values for this component's properties
UOrganComponent::UOrganComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOrganComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrganComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UOrganComponent::OnTargetHit_Implementation(float Damage, const FHitResult& HitResult)
{
	if (bIsVitalOrgan)
	{
		UE_LOG(LogTemp, Warning, TEXT("TRAFIENIE KRYTYCZNE w: %s"), *GetOwner()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Trafienie w zwykły organ"));
	}

	return bIsVitalOrgan; 
}
