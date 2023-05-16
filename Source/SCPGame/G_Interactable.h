// Simon Borghese (c) 2023, See License.txt for details (if included with distro)

#pragma once

#include "CoreMinimal.h"
#include "FPSPlayer.h"
#include "GameFramework/Actor.h"
#include "G_Interactable.generated.h"

UCLASS()
class SCPGAME_API AG_Interactable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AG_Interactable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent *PickupArea;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OtherComp, class AActor* OtherActor, class UPrimitiveComponent* HitComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OtherComp, class AActor* OtherActor, class UPrimitiveComponent* HitComp, int32 OtherBodyIndex);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnInteract(class AFPSPlayer *Player);

};

