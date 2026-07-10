// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AncientFuelComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONCRAWLER_API UAncientFuelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAncientFuelComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuel")
	float MaxFuel = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Fuel")
	float CurrentFuel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fuel")
	float DrainRate = 2.0f; // Ile paliwa znika co sekundę

	// Zmienna do obsługi czasu i funkcja zjadająca paliwo
	FTimerHandle FuelTimerHandle;
	void DrainFuel();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
