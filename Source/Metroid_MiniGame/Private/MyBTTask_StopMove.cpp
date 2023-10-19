// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTTask_StopMove.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UMyBTTask_StopMove::UMyBTTask_StopMove()
{
	NodeName = "StopMovement";
}

EBTNodeResult::Type UMyBTTask_StopMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	 Super::ExecuteTask(OwnerComp, NodeMemory);
	AAIController* Controller = Cast<AAIController>( OwnerComp.GetAIOwner()->GetCharacter()->Controller);
	if(IsValid(Controller))
	{
		UE_LOG(LogTemp,Warning,TEXT("Controller is here "));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Controller is NOt here "));
		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Succeeded;
}
