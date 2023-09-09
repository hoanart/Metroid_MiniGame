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
private:


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
	
	const TObjectPtr<UStaticMeshComponent>& GetRifleGuns() const;
	
private:
	UFUNCTION()
	void Equip();
	//PROPERTY
public:


private:
	UPROPERTY(VisibleAnywhere, BlueprintGetter= IsEquip, BlueprintSetter= SetEquip,Category = "Gun")
	bool mbEquip;
	UPROPERTY(EditAnywhere,BlueprintGetter= IsRiffle, BlueprintSetter= SetRiffle, Category = "Gun")
	bool mbRiffle;
	
	//UObject
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> EquipAction;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> mRifleGunHold;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Components",meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> mRifleGunStore;

};
