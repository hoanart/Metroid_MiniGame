// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIPatrolPathPoint.generated.h"

UCLASS()
class METROID_MINIGAME_API AAIPatrolPathPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIPatrolPathPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere,Category = "Components")
	TObjectPtr<USceneComponent> mRoot;

	UPROPERTY(VisibleAnywhere,Category = "Components",meta=(AllowPrivateAccess=true))
	TObjectPtr<UStaticMeshComponent> mPathPoint;

	UPROPERTY(VisibleAnywhere,Category = "Components",meta=(AllowPrivateAccess=true))
	TObjectPtr<class UArrowComponent> mArrow;
	
	
};
