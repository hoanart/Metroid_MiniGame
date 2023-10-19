// Fill out your copyright notice in the Description page of Project Settings.


#include "RatAIController.h"

#include "AIPatrolPathPoint.h"
#include "EnemyBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionSystem.h"
#include "Perception/AIPerceptionTypes.h"


class AAIPatrolPathPoint;

ARatAIController::ARatAIController()
{
}

void ARatAIController::BeginPlay()
{
	AAIControllerBase::BeginPlay();
	PossessedEnemy = Cast<AEnemyBase>(GetCharacter());
	if(!IsValid(PossessedEnemy))
	{
		UE_LOG(LogTemp,Warning,TEXT("Nedd a EnemyBase type "));
		return;
	}
	TMap<TObjectPtr<AAIPatrolPathPoint>, float> PatrolPath = PossessedEnemy->GetPatrolPath();
	TArray<TObjectPtr<AAIPatrolPathPoint>> PatrolPoints;
	
	if(PatrolPath.GetKeys(PatrolPoints)==2)
	{
		GetBlackboardComponent()->SetValueAsVector("L_PatrolPoint",PatrolPoints[0]->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector("R_PatrolPoint",PatrolPoints[1]->GetActorLocation());	
	}
	
	GetBlackboardComponent()->SetValueAsFloat("L_Time",PatrolPath.FindRef(PatrolPoints[0]));
	GetBlackboardComponent()->SetValueAsFloat("R_Time",PatrolPath.FindRef(PatrolPoints[1]));
}

void ARatAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus AIStimulus)
{
	AAIControllerBase::OnTargetPerceptionUpdated(Actor, AIStimulus);
	auto GetSense = UAIPerceptionSystem::GetSenseClassForStimulus(this,AIStimulus);
	const TObjectPtr<ACharacter> Player = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
	
	if(Actor!=Player)
	{
		return;
	}
	GetBlackboardComponent()->SetValueAsVector("TargetLoc",Player->GetActorLocation());
	GetBlackboardComponent()->SetValueAsBool("HasSeenPlayer",AIStimulus.WasSuccessfullySensed());		
	
	
}

void ARatAIController::SetMoving(const bool& bMoving)
{
	mbMoving = bMoving;
}

const bool& ARatAIController::IsMoving() const
{
	return mbMoving;
}

