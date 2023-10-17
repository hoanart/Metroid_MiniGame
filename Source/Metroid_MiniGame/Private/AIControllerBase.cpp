// Fill out your copyright notice in the Description page of Project Settings.


#include "AIControllerBase.h"

#include "GameFramework/Character.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AAIControllerBase::AAIControllerBase()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerception");
	SetPerceptionComponent(*AIPerception);
	AISightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("AISightConfig");
	if(IsValid(AISightConfig))
	{
		AISightConfig->DetectionByAffiliation.bDetectEnemies = true;
		AISightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		AISightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		AISightConfig->PointOfViewBackwardOffset = 200.0f;
	}

	AAIController::GetPerceptionComponent()->SetDominantSense(AISightConfig->GetSenseImplementation());
	AAIController::GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this,&AAIControllerBase::OnTargetPerceptionUpdated);
	AAIController::GetPerceptionComponent()->ConfigureSense(*AISightConfig);
}

void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	check(IsValid(AIBehavior));
	RunBehaviorTree(AIBehavior);
	PossessedPawn = GetPawn();
	if(IsValid(PossessedPawn))
	{
		UE_LOG(LogTemp,Warning,TEXT("%s "),*PossessedPawn->GetActorLocation().ToString());
		GetBlackboardComponent()->SetValueAsVector("InitLoc",PossessedPawn->GetActorLocation());
		//GetBlackboardComponent()->SetValueAsVector("MoveLoc",PossessedPawn->GetActorLocation()+FVector(1000.0f,0.0f,0.0f));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("NOT HERE "));
	}
	
}

void AAIControllerBase::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus AIStimulus)
{
	auto GetSense = UAIPerceptionSystem::GetSenseClassForStimulus(this,AIStimulus);
	if(const TObjectPtr<ACharacter> Player =Cast<ACharacter>(Actor))
	{
		UE_LOG(LogTemp,Warning,TEXT("PLAYER DETECTED : %s"),*Player.GetName());
	}
}
