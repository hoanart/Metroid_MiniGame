// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerIsInRange.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API UBTService_PlayerIsInRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UBTService_PlayerIsInRange();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
private:
	UPROPERTY(EditAnywhere)
	float MeleeAttackRange;
};
