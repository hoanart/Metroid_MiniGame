// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Rotate.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/PawnMovementComponent.h"

UBTTask_Rotate::UBTTask_Rotate()
{
	NodeName ="Rotate";
	//bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Rotate::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	TObjectPtr<APawn> Enemy = Cast<APawn>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));
	if(!IsValid(Enemy))
	{
		return EBTNodeResult::Failed;
	}
	
	FRotator NewRotator = FRotator(Enemy->GetActorRotation().Pitch,-Enemy->GetActorRotation().Yaw,Enemy->GetActorRotation().Roll);
	
	Enemy->SetActorRotation(FMath::RInterpTo(Enemy->GetActorRotation(), NewRotator,GetWorld()->GetDeltaSeconds(),5.0f));
	Enemy->GetMovementComponent()->Velocity.Set(0.0f,0.0f,0.0f);
	return EBTNodeResult::Succeeded;	

	
}

