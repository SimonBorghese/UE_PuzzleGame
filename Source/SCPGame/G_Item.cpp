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

	PickupArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Pickup Collider"));
	PickupArea->SetupAttachment(RootComponent);
	PickupArea->OnComponentBeginOverlap.AddDynamic(this, &AG_Item::OnOverlapBegin);
	PickupArea->OnComponentEndOverlap.AddDynamic(this, &AG_Item::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AG_Item::BeginPlay()
{
	Super::BeginPlay();
	
}

void AG_Item::OnOverlapBegin(UPrimitiveComponent* OtherComp, class AActor* OtherActor,
	UPrimitiveComponent* HitComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->GetClass() && OtherActor->GetClass() == AFPSPlayer::StaticClass())
	{
		AFPSPlayer *FPSPlayer = static_cast<AFPSPlayer*>(OtherActor);
		FPSPlayer->AddReachableItem(this);
	}
}

void AG_Item::OnOverlapEnd(UPrimitiveComponent* OtherComp, AActor* OtherActor,
	UPrimitiveComponent* ThisComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->GetClass() && OtherActor->GetClass() == AFPSPlayer::StaticClass())
	{
		AFPSPlayer *FPSPlayer = static_cast<AFPSPlayer*>(OtherActor);
		// EXPENSIVE OPERATION!!!
		FPSPlayer->RemoveReachableItem(this);
	}
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

