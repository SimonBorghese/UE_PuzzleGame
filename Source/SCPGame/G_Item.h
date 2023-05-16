// Simon Borghese (c) 2023, See License.txt for details (if included with distro)
#pragma once

#include "CoreMinimal.h"
#include "G_Interactable.h"
#include "GameFramework/Actor.h"
#include "G_Item.generated.h"

UCLASS()
class SCPGAME_API AG_Item : public AG_Interactable
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
	
public:	
	// Called every frame
	// Still don't do anything
	virtual void Tick(float DeltaTime) override;

	void PickupItem();

	virtual void OnInteract(class AFPSPlayer *Player) override;

};
