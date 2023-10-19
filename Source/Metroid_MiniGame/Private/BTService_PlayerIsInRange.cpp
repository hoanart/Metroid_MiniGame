// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerIsInRange.h"

#include "AIController.h"
#include "EnemyBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UBTService_PlayerIsInRange::UBTService_PlayerIsInRange()
{
	NodeName= "Player Is In Range";
	MeleeAttackRange =150.0f;
}

void UBTService_PlayerIsInRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	FVector Diff = OwnerComp.GetAIOwner()->GetCharacter()->GetActorLocation() - UGameplayStatics::GetPlayerCharacter(GetWorld(),0)->GetActorLocation();
	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(),Diff.Length()<MeleeAttackRange);
	if(!OwnerComp.GetBlackboardComponent()->GetValueAsBool(GetSelectedBlackboardKey()))
	{
		TObjectPtr<AEnemyBase> Enemy = Cast<AEnemyBase>(OwnerComp.GetAIOwner()->GetCharacter());
		Enemy->SetAttack(OwnerComp.GetBlackboardComponent()->GetValueAsBool(GetSelectedBlackboardKey()));
	}
	
}
