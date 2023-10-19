// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ChaseThePlayer.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API UBTTask_ChaseThePlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_ChaseThePlayer();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
