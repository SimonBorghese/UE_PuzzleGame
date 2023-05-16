// Simon Borghese (c) 2023, See License.txt for details (if included with distro)


#include "G_Item.h"

#include "FPSPlayer.h"
#include "Components/BoxComponent.h"

// Sets default values
AG_Item::AG_Item()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	WorldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("World Mesh"));
	WorldMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AG_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AG_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AG_Item::PickupItem()
{
	WorldMesh->SetHiddenInGame(true);
	WorldMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PrimaryActorTick.bCanEverTick = false;
	PickupArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AG_Item::OnInteract(AFPSPlayer* Player)
{
	Super::OnInteract(Player);
	PickupItem();
	Player->AddInventoryItem(this);
}

