// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "AIBehavior.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	AIBehavior = CreateDefaultSubobject<UAIBehavior>("AIBehavior");
	
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase::SetAttack(const bool& bAttack)
{
	mbAttack = bAttack;
}

const bool& AEnemyBase::IsAttack() const
{
	return mbAttack;
}

const TMap<TObjectPtr<AAIPatrolPathPoint>, float>& AEnemyBase::GetPatrolPath() const
{
	return AIBehavior->GetPatrolPathMap();
}


