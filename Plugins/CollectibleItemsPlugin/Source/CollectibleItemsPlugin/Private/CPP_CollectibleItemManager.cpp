#include "CPP_CollectibleItemManager.h"

#define Print(x) if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT(x)); }

void ACPP_CollectibleItemManager::AddPoints(int Points)
{
	// Increase Score and print some info

	CurrentScore += Points;

	if (PrintDebug)
	{
		Print("+" + FString::FromInt(Points) + " POINTS!\nSCORE: " + FString::FromInt(CurrentScore));
	}

	ACPP_CollectibleItemManager::ScoreChanged.Broadcast();
}

int ACPP_CollectibleItemManager::GetCurrentScore()
{
	return CurrentScore;
}

void ACPP_CollectibleItemManager::ResetCurrentScore()
{
	CurrentScore = 0;
}
