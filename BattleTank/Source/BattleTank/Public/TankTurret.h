// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * Set max turret's rotating speed
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	//Sensible default
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreePerSec = 45;
};
