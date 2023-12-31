// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MyBTTask_StopMove.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API UMyBTTask_StopMove : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UMyBTTask_StopMove();
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;	
};
