// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_AttackThePlayer.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API UBTTask_AttackThePlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTTask_AttackThePlayer();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
