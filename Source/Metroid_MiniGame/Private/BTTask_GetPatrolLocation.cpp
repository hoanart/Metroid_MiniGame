// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_GetPatrolLocation.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

UBTTask_GetPatrolLocation::UBTTask_GetPatrolLocation()
{
	NodeName = "GetPatrolLocation";
}

EBTNodeResult::Type UBTTask_GetPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	 Super::ExecuteTask(OwnerComp, NodeMemory);
	TObjectPtr<ACharacter> Enemy = OwnerComp.GetAIOwner()->GetCharacter();

	if(!IsValid(Enemy))
	{
		return EBTNodeResult::Failed;
	}
	if(OwnerComp.GetBlackboardComponent()->GetValueAsBool("IsReached"))
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("IsReached",false);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector("MoveLoc",
		OwnerComp.GetBlackboardComponent()->GetValueAsVector("InitLoc"));
		//Enemy->SetActorLocation(FMath::VInterpTo(Enemy->GetActorLocation(),OwnerComp.GetBlackboardComponent()->GetValueAsVector("InitLoc"),GetWorld()->GetDeltaSeconds(),2.0f));
		AAIController* Controller = Cast<AAIController>( OwnerComp.GetAIOwner()->GetCharacter()->Controller);
		if(IsValid(Controller))
		{
			Controller->MoveToLocation(OwnerComp.GetBlackboardComponent()->GetValueAsVector("InitLoc"));
		}
		OwnerComp.GetBlackboardComponent()->SetValueAsRotator("PatrolRotator",FRotator(0.0f,180.0f,0.0f));
		
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool("IsReached",true);
		OwnerComp.GetBlackboardComponent()->SetValueAsVector("MoveLoc",Enemy->GetActorLocation()+FVector(1000.0f,0.0f,0.0f));
		//Enemy->SetActorLocation(FMath::VInterpTo(Enemy->GetActorLocation(),OwnerComp.GetBlackboardComponent()->GetValueAsVector("MoveLoc"),GetWorld()->GetDeltaSeconds(),2.0f));

		AAIController* Controller = Cast<AAIController>( OwnerComp.GetAIOwner()->GetCharacter()->Controller);
		if(IsValid(Controller))
		{
			Controller->MoveToLocation(OwnerComp.GetBlackboardComponent()->GetValueAsVector("MoveLoc"));
		}
		OwnerComp.GetBlackboardComponent()->SetValueAsRotator("PatrolRotator",FRotator(0.0f,-180.0f,0.0f));
	}
	//OwnerComp.GetBlackboardComponent()->SetValueAsVector("MoveLoc",Enemy->GetActorLocation()+FVector(500.0f,0.0f,0.0f));
	
	//OwnerComp.GetBlackboardComponent()->SetValueAsVector("InitLoc",Enemy->GetActorLocation());

	return EBTNodeResult::Succeeded;
}
