// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "EnemyBase.generated.h"

UCLASS()
class METROID_MINIGAME_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,FVector NormalImpulse,const FHitResult& Hit );
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintSetter)
	void SetAttack(const bool& bAttack);
	UFUNCTION(BlueprintGetter)
	const bool& IsAttack() const;

	UFUNCTION()
	virtual void Attack();
public:
	const TMap<TObjectPtr<class AAIPatrolPathPoint>, float>& GetPatrolPath() const;
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess=true))
	TObjectPtr<UStaticMeshComponent> EnemyStaticMeshComponent;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta=(AllowPrivateAccess=true))
	TObjectPtr<class UAIBehavior> AIBehavior;
private:
	UPROPERTY(VisibleAnywhere,BlueprintGetter=IsAttack,BlueprintSetter=SetAttack)
	bool mbAttack;
	UPROPERTY(EditAnywhere,Category= "Animation")
	TObjectPtr<UAnimMontage> AttackMontage;
};
