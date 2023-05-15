// Simon Borghese (c) 2023, See License.txt for details (if included with distro)


#include "P_PlayerInvetory.h"

// Sets default values for this component's properties
UP_PlayerInvetory::UP_PlayerInvetory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UP_PlayerInvetory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UP_PlayerInvetory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<AG_Item*> UP_PlayerInvetory::GetInventory()
{
	// Duplicate current array
	return TArray<AG_Item*>(CurrentInventory);
}

AG_Item* UP_PlayerInvetory::GetItem(int Index)
{
	return CurrentInventory[Index];
}
int		 UP_PlayerInvetory::GetItemIndex(AG_Item* Item)
{
	auto InvItem = CurrentInventory.Find(Item);
	if (InvItem != INDEX_NONE)
	{
		return InvItem;
	}
	return -1;
}
void	 UP_PlayerInvetory::RemoveItem(AG_Item *Item)
{
	CurrentInventory.Remove(Item);
}
void	 UP_PlayerInvetory::RemoveItem(int ItemIndex)
{
	CurrentInventory.RemoveAt(ItemIndex);
}

int UP_PlayerInvetory::AddItem(AG_Item* Item)
{
	CurrentInventory.Add(Item);
	return CurrentInventory.Find(Item);
}
