// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIControllerBase.h"
#include "RatAIController.generated.h"
/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API ARatAIController : public AAIControllerBase
{
	GENERATED_BODY()
public:
	ARatAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus AIStimulus) override;

public:
		void SetMoving(const bool& bMoving);
	const bool& IsMoving() const;
private:
	//UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Player",meta=(AllowPrivateAccess=true))       
	TObjectPtr<class AEnemyBase> PossessedEnemy;

	bool mbMoving;
};
