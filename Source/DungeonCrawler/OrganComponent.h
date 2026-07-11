// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrganTargetInterface.h"
#include "Components/BoxComponent.h"
#include "OrganComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER_API UOrganComponent : public UBoxComponent, public IOrganTargetInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrganComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// Czy to punkt krytyczny (np. serce, rdzeń)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Organ")
	bool bIsVitalOrgan = false;

	// Implementacja funkcji z interfejsu
	virtual bool OnTargetHit_Implementation(float Damage, const FHitResult& HitResult) override;

		
};
