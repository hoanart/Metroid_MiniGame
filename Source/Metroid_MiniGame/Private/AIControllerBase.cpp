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
	check(IsValid(AIBehaviorTree));
	RunBehaviorTree(AIBehaviorTree);
	
}

void AAIControllerBase::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus AIStimulus)
{
	
	// if(const TObjectPtr<ACharacter> Player =Cast<ACharacter>(Actor))
	// {
	// 	UE_LOG(LogTemp,Warning,TEXT("PLAYER DETECTED : %s"),*Player.GetName());
	// }
}
