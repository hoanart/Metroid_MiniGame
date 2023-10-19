// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AttackThePlayer.h"

#include "AIController.h"
#include "EnemyBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_AttackThePlayer::UBTTask_AttackThePlayer()
{
	NodeName = "Attack The Player";
	bNotifyTick = false;
}

EBTNodeResult::Type UBTTask_AttackThePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	 Super::ExecuteTask(OwnerComp, NodeMemory);
	bool isInRange = OwnerComp.GetBlackboardComponent()->GetValueAsBool("IsInRange");
	TObjectPtr<AEnemyBase> Enemy = Cast<AEnemyBase>(OwnerComp.GetAIOwner()->GetCharacter());
	if(isInRange)
	{
		Enemy->SetAttack(isInRange);
	}
	else
	{
		Enemy->SetAttack(false);
		
	}

	
	return EBTNodeResult::Succeeded;
}
