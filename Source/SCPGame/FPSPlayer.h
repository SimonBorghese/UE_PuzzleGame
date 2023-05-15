// Simon Borghese (c) 2023, See License.txt for details (if included with distro)

#pragma once

#include <vector>
#include <map>

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSPlayer.generated.h"

UCLASS()
class SCPGAME_API AFPSPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FVector3d MovementTarget;

	UPROPERTY()
	FVector3d LookTarget;
	
	void AddForward(float axis);
	void AddRight(float axis);
	void AddPitch(float axis);
	void AddYaw(float axis);

	void AddJump();

	UPROPERTY(EditAnywhere)
	class UCameraComponent *Camera;
	
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	float LookSpeed = 1.0f;

	UPROPERTY(EditAnywhere)
	class UP_PlayerInvetory *Inventory;

	UPROPERTY(VisibleAnywhere)
	TArray<AG_Item*> HoldableItems;


	UFUNCTION()
	void PickupNearest();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void AddReachableItem(AG_Item* Item);

	UFUNCTION()
	void RemoveReachableItem(AG_Item* Item);

};
