// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ChaseThePlayer.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UBTTask_ChaseThePlayer::UBTTask_ChaseThePlayer()
{
	NodeName = "Chase The Player";
	bNotifyTick = false;
}

EBTNodeResult::Type UBTTask_ChaseThePlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	FVector TargetLoc = OwnerComp.GetBlackboardComponent()->GetValueAsVector(GetSelectedBlackboardKey());
	OwnerComp.GetAIOwner()->MoveToLocation(UGameplayStatics::GetPlayerCharacter(GetWorld(),0)->GetActorLocation());
	// if(OwnerComp.GetAIOwner()->GetCharacter()->SetActorLocation(FMath::VInterpTo(OwnerComp.GetAIOwner()->GetCharacter()->GetActorLocation(),UGameplayStatics::GetPlayerCharacter(GetWorld(),0)->GetActorLocation(),GetWorld()->DeltaTimeSeconds,2.0f)))
	// {
	// 	return EBTNodeResult::Succeeded;
	// }
	return EBTNodeResult::Succeeded;
}

void UBTTask_ChaseThePlayer::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

