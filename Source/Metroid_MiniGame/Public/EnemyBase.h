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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintSetter)
	void SetAttack(const bool& bAttack);
	UFUNCTION(BlueprintGetter)
	const bool& IsAttack() const;
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
};
