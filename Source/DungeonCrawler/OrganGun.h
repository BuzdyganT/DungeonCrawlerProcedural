// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrganGun.generated.h"

UCLASS()
class DUNGEONCRAWLER_API AOrganGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrganGun();
	void Fire(const FVector& StartLocation, const FVector& Direction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* GunMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	float TraceRange = 2000.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
