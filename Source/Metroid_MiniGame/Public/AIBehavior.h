// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIBehavior.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class METROID_MINIGAME_API UAIBehavior : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAIBehavior();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	const TMap<TObjectPtr<class AAIPatrolPathPoint>, float>& GetPatrolPathMap() const;

private:
	UPROPERTY(EditInstanceOnly,Category = "PatrolPath")
	TMap<TObjectPtr<class AAIPatrolPathPoint>, float> mPatrolPathMap;
		
};
