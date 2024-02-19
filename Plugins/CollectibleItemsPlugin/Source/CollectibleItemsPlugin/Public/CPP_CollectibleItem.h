#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/MeshComponent.h"
#include "CPP_CollectibleItemManager.h"
#include "Kismet/GameplayStatics.h"

#include "CPP_CollectibleItem.generated.h"

UCLASS()
class COLLECTIBLEITEMSPLUGIN_API ACPP_CollectibleItem : public AActor
{
	GENERATED_BODY()

public:
	ACPP_CollectibleItem();

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		ACPP_CollectibleItemManager* Manager = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		USphereComponent* SphereCollision = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		UStaticMeshComponent* StaticMesh = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		int Points = 0;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
