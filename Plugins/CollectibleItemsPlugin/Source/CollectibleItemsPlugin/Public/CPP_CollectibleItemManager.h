#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

#include "CPP_CollectibleItemManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScoreChanged);

UCLASS()
class COLLECTIBLEITEMSPLUGIN_API ACPP_CollectibleItemManager : public AActor
{
	GENERATED_BODY()	

private:
	UPROPERTY()
		int CurrentScore = 0;

public:
	UPROPERTY(BlueprintAssignable, Category = "Score")
		FScoreChanged ScoreChanged;

	UFUNCTION(BlueprintCallable, Category = "Score")
		void AddPoints(int Points);

	UFUNCTION(BlueprintCallable, Category = "Score")
		int GetCurrentScore();

	UFUNCTION(BlueprintCallable, Category = "Score")
		void ResetCurrentScore();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
		bool PrintDebug = false;
};
