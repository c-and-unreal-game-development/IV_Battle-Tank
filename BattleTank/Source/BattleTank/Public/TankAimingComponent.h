// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"		// Inherited
#include "TankAimingComponent.generated.h"

// Enum for aim states
UENUM(BlueprintType)
enum class EAimingStatus : uint8
{
	AE_Locked		UMETA(DisplayName = "Locked"),
	AE_Aiming		UMETA(DisplayName = "Aiming"),
	AE_Reloading	UMETA(DisplayName = "Reloading")
};

// Forward Declaration: let header know that the class exist
class UTankBarrel;		
class UTankTurret;

/**
 * For Tank to move turret and barrel to the aimed target
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = State)
	EAimingStatus AimStatus = EAimingStatus::AE_Reloading;

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	// Method for elevating barrel in PITCH (Y value) and rotating turret in YAW (Z value)
	void MoveComponent(FVector AimDirection);
};
