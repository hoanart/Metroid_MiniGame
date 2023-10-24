// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RifleProjectile.generated.h"

UCLASS()
class METROID_MINIGAME_API ARifleProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifleProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSpawnFSMasterField(const FHitResult& Hit);
	
private:
	UFUNCTION()
	void OnHit(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	
private:
	FTimerHandle delayTimer;
	UPROPERTY()
	bool mbHit;
private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Bullet",meta = (AllowPrivateAccess = true))
	TObjectPtr<class UProjectileMovementComponent> mProjectileComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<class USphereComponent> mSphereComp;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> mCylinder;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<class UParticleSystemComponent> mExplosionParticle;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<class UParticleSystemComponent> mMuzzleParticle;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<class UAudioComponent> mExplosionCue;
	
};
