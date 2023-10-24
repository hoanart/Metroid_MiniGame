// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBase.h"
#include "Rat.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API ARat : public AEnemyBase
{
	GENERATED_BODY()
	ARat();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void OnHit(UPrimitiveComponent* HitComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit ) override;
	virtual void Attack()  override;
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess = true))
	TObjectPtr<class USphereComponent> HeadSphere;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess = true))
	TObjectPtr<class UHealthComponent> HealthComponent;
};
