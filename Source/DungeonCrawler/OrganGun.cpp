// Fill out your copyright notice in the Description page of Project Settings.


#include "OrganGun.h"
#include "DrawDebugHelpers.h"
#include "OrganComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

// Sets default values
AOrganGun::AOrganGun()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	RootComponent = RootComp;

	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetupAttachment(RootComponent); 
}

// Called when the game starts or when spawned
void AOrganGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrganGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOrganGun::Fire(const FVector& StartLocation, const FVector& Direction)
{
	UWorld* World = GetWorld();
	if (!World) return;

	FVector EndLocation = StartLocation + (Direction * TraceRange);
	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);
	CollisionParams.AddIgnoredActor(GetOwner()); // Ignorujemy postać gracza

	bool bHit = World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);

	DrawDebugLine(World, StartLocation, EndLocation, FColor::Red, false, 2.0f, 0, 2.0f);

	if (bHit)
	{
		// Czy trafiliśmy komponent, który implementuje nasz interfejs?
		if (HitResult.GetComponent()->Implements<UOrganTargetInterface>())
		{
			bool bWasVital = IOrganTargetInterface::Execute_OnTargetHit(HitResult.GetComponent(), 10.0f, HitResult);
        
			DrawDebugBox(GetWorld(), HitResult.ImpactPoint, FVector(8.f), bWasVital ? FColor::Red : FColor::Green, false, 2.0f);
		}
		else
		{
			DrawDebugBox(GetWorld(), HitResult.ImpactPoint, FVector(5.f), FColor::Blue, false, 2.0f);
		}
	}
}
