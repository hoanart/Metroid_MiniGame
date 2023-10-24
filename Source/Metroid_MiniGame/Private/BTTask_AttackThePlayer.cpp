// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_AttackThePlayer.h"

#include "AIController.h"
#include "EnemyBase.h"
#include "Rat.h"
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

	FTimerHandle TimerHandle;
	
	bool isInRange = OwnerComp.GetBlackboardComponent()->GetValueAsBool("IsInRange");
	//TObjectPtr<AEnemyBase> Enemy = Cast<AEnemyBase>(OwnerComp.GetAIOwner()->GetCharacter());
	TObjectPtr<ARat> Enemy = Cast<ARat>(OwnerComp.GetAIOwner()->GetCharacter());

	if(!isInRange)
	{
		return EBTNodeResult::Failed;
	}
	
	Enemy->Attack();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle,[this,&TimerHandle,&OwnerComp]()
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
		//UE_LOG(LogTemp,Warning,TEXT("TIMER "));
	}, 1.5f,false);
	return EBTNodeResult::InProgress;
}
