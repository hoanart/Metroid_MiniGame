// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Metroid_MiniGame/Metroid_MiniGameCharacter.h"
#include "MetroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API AMetroCharacter : public AMetroid_MiniGameCharacter
{
	GENERATED_BODY()
public:
	AMetroCharacter();
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
private:
	virtual void Tick(float DeltaSeconds) override;

	//FUNCTION
public:
	UFUNCTION(BlueprintGetter)
	const bool& IsRiffle() const;
	UFUNCTION(BlueprintSetter)
	void SetRiffle(const bool& bRiffle);
	
	UFUNCTION(BlueprintGetter)
	const bool& IsEquip() const;
	UFUNCTION(BlueprintSetter)
	void SetEquip(const bool& bEquip);

	UFUNCTION(BlueprintGetter)
	const bool& IsInAir() const;
	UFUNCTION(BlueprintSetter)
	void SetInAir(const bool& bInAir);
	
	UFUNCTION(BlueprintGetter)
	const FVector& GetGunOffset() const;
	const TObjectPtr<UStaticMeshComponent>& GetRifleGuns() const;
	
private:
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	UFUNCTION()
	void Equip();
	UFUNCTION()
	void Fire();
	//PROPERTY
public:
	UFUNCTION(BlueprintImplementableEvent)
	void CheckJump();
private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter= IsEquip, BlueprintSetter= SetEquip,Category = "Gun")
	bool mbEquip;
	UPROPERTY(EditAnywhere,BlueprintGetter= IsRiffle, BlueprintSetter= SetRiffle, Category = "Gun")
	bool mbRiffle;
	UPROPERTY(EditAnywhere,BlueprintGetter= IsInAir, BlueprintSetter = SetInAir, Category = "Gun")
	bool mbInAir;
	UPROPERTY(EditAnywhere,BlueprintGetter= GetGunOffset, Category = "Gun")
	FVector mGunOffset;
	
	//UObject
private:
	UPROPERTY(EditAnywhere, Category = "Gun")
	TObjectPtr<class USoundBase> ShotSound;
	UPROPERTY(EditAnywhere,Category = "Gun")
	TSubclassOf<class ARifleProjectile> mRifleProjectileClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> EquipAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<class USphereComponent> mSphereComp;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<USceneComponent> mProjectilePosition;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> mRifleGunHold;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> mRifleGunStore;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<class UHealthComponent> HealthComponent;
};

