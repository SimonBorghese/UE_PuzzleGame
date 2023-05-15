// Simon Borghese (c) 2023, See License.txt for details (if included with distro)

#pragma once

#include "CoreMinimal.h"
#include "G_Item.h"
#include "Components/ActorComponent.h"
#include "P_PlayerInvetory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCPGAME_API UP_PlayerInvetory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UP_PlayerInvetory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TArray<AG_Item*> CurrentInventory;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	TArray<AG_Item*> GetInventory();

	AG_Item* GetItem(int Index);
	int		 GetItemIndex(AG_Item* Item);
	void	 RemoveItem(AG_Item *Item);
	void	 RemoveItem(int ItemIndex);
	int		 AddItem(AG_Item *Item);
};
