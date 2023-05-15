// Simon Borghese (c) 2023, See License.txt for details (if included with distro)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "G_Item.generated.h"

UCLASS()
class SCPGAME_API AG_Item : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AG_Item();

protected:
	// Called when the game starts or when spawned
	// This item is just a base class, don't do anything
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent *WorldMesh;

	UPROPERTY(EditAnywhere)
	class UBoxComponent *PickupArea;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OtherComp, class AActor* OtherActor, class UPrimitiveComponent* HitComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OtherComp, class AActor* OtherActor, class UPrimitiveComponent* HitComp, int32 OtherBodyIndex);

public:	
	// Called every frame
	// Still don't do anything
	virtual void Tick(float DeltaTime) override;

	void PickupItem();

};
