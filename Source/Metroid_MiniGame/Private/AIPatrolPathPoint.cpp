// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPatrolPathPoint.h"

#include "Components/ArrowComponent.h"

// Sets default values
AAIPatrolPathPoint::AAIPatrolPathPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mRoot = CreateDefaultSubobject<USceneComponent>("RootComponent");
	RootComponent =mRoot;

	mPathPoint = CreateDefaultSubobject<UStaticMeshComponent>("PathPoint");
	mPathPoint->SetupAttachment(RootComponent);
	mArrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	mArrow->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AAIPatrolPathPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIPatrolPathPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

