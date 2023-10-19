// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()
public:
	AAIControllerBase();

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	virtual void OnTargetPerceptionUpdated(AActor* Actor,FAIStimulus AIStimulus);
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="AI", meta = (AllowPrivateAccess = true))
	TObjectPtr<class UBehaviorTree> AIBehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI",meta = (AllowPrivateAccess = true))
	TObjectPtr<class UAIPerceptionComponent> AIPerception;
	
	UPROPERTY()
	TObjectPtr<class UAISenseConfig_Sight> AISightConfig;

	
};
