#include "CPP_CollectibleItem.h"

#define Print(x) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x)); }

ACPP_CollectibleItem::ACPP_CollectibleItem()
{
	PrimaryActorTick.bCanEverTick = true;

	// Collider setup

	SphereCollision = CreateDefaultSubobject<USphereComponent>(FName("SphereCollision"));
	SetRootComponent(SphereCollision);
	SphereCollision->InitSphereRadius(100.0f);
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_CollectibleItem::OnOverlapBegin);

	// Static Mesh setup

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));
}

void ACPP_CollectibleItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Fetching Manager

	TArray<AActor*> Managers;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPP_CollectibleItemManager::StaticClass(), Managers);

	for (size_t i = 0; i < Managers.Num(); i++)
	{
		Manager = Cast<ACPP_CollectibleItemManager>(Managers[0]);
	}

	// If there is a Manager add points and destroy actor

	if (!Manager)
	{
		Print("MISSING MANAGER");
	}
	else
	{
		Manager->AddPoints(Points);

		Destroy();
	}
}
