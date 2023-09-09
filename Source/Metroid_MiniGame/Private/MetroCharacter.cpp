// Fill out your copyright notice in the Description page of Project Settings.


#include "MetroCharacter.h"

#include "EnhancedInputComponent.h"

AMetroCharacter::AMetroCharacter()
{
	
	mRifleGunHold= CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("RiffleGun1")) );
	mRifleGunHold->SetupAttachment(GetMesh(),FName("GunHold"));

	mRifleGunStore= CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("RiffleGun2")) );
	mRifleGunStore->SetupAttachment(GetMesh(),FName("GunStore"));

}

void AMetroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMetroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(EquipAction,ETriggerEvent::Triggered ,this,&AMetroCharacter::Equip);
	}
}

const bool& AMetroCharacter::IsRiffle() const
{
	return mbRiffle;
}

void AMetroCharacter::SetRiffle(const bool& bRiffle)
{
	mbRiffle = bRiffle;
}

const bool& AMetroCharacter::IsEquip() const
{
	return mbEquip;
}

void AMetroCharacter::SetEquip(const bool& bEquip)
{
	mbEquip = bEquip;
}

const TObjectPtr<UStaticMeshComponent>& AMetroCharacter::GetRifleGuns() const
{
	return mRifleGunHold;
}


void AMetroCharacter::Equip()
{
	if(mbEquip)
	{
		mbRiffle = !mbRiffle;
		if(mbRiffle)
		{
			UE_LOG(LogTemp,Warning,TEXT("setRiffle"));
			mRifleGunHold->SetHiddenInGame(false);
			mRifleGunStore->SetHiddenInGame(true);
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("UnsetRiffle"));
			mRifleGunHold->SetHiddenInGame(true);
			mRifleGunStore->SetHiddenInGame(false);
		}
	}
}


