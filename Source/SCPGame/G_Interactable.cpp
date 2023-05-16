// Simon Borghese (c) 2023, See License.txt for details (if included with distro)


#include "G_Interactable.h"

#include "FPSPlayer.h"
#include "Components/BoxComponent.h"

// Sets default values
AG_Interactable::AG_Interactable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PickupArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Pickup Collider"));
	PickupArea->SetupAttachment(RootComponent);
	PickupArea->OnComponentBeginOverlap.AddDynamic(this, &AG_Interactable::OnOverlapBegin);
	PickupArea->OnComponentEndOverlap.AddDynamic(this, &AG_Interactable::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AG_Interactable::BeginPlay()
{
	Super::BeginPlay();
	
}

void AG_Interactable::OnOverlapBegin(UPrimitiveComponent* OtherComp, AActor* OtherActor, UPrimitiveComponent* HitComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->GetClass() && OtherActor->GetClass() == AFPSPlayer::StaticClass())
	{
		AFPSPlayer *FPSPlayer = static_cast<AFPSPlayer*>(OtherActor);
		FPSPlayer->AddReachableItem(this);
	}
}

void AG_Interactable::OnOverlapEnd(UPrimitiveComponent* OtherComp, AActor* OtherActor, UPrimitiveComponent* HitComp,
	int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->GetClass() && OtherActor->GetClass() == AFPSPlayer::StaticClass())
	{
		AFPSPlayer *FPSPlayer = static_cast<AFPSPlayer*>(OtherActor);
		// EXPENSIVE OPERATION!!!
		FPSPlayer->RemoveReachableItem(this);
	}
}

// Called every frame
void AG_Interactable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AG_Interactable::OnInteract(AFPSPlayer* Player)
{
}