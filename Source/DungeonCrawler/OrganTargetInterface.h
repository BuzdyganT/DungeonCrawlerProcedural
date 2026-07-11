#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "OrganTargetInterface.generated.h"

UINTERFACE(MinimalAPI)
class UOrganTargetInterface : public UInterface
{
	GENERATED_BODY()
};

class DUNGEONCRAWLER_API IOrganTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	bool OnTargetHit(float Damage, const FHitResult& HitResult);
};