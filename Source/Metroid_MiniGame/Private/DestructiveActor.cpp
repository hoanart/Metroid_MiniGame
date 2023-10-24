// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructiveActor.h"

#include "GeometryCollection/GeometryCollectionComponent.h"

// Sets default values
ADestructiveActor::ADestructiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComp->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ADestructiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestructiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

