// Fill out your copyright notice in the Description page of Project Settings.


#include "MetroCharacter.h"

#include "EnhancedInputComponent.h"

AMetroCharacter::AMetroCharacter()
{
	mRifleGuns.Reserve(2);
	for(int i =0;i<2;i++)
	{
		TObjectPtr<UStaticMeshComponent> riffle= CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("RiffleGun %d "),i) );
		riffle->SetupAttachment(GetMesh(),FName("GunHold"));
		mRifleGuns.Add(riffle);
	}

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

const TArray<TObjectPtr<UStaticMeshComponent>>& AMetroCharacter::GetRifleGuns() const
{
	return mRifleGuns;
}


void AMetroCharacter::Equip()
{
	if(mbEquip)
	{
		if(mbRiffle)
		{
			mRifleGuns[0]->SetHiddenInGame(true);
			mRifleGuns[1]->SetHiddenInGame(false);
		}
		else
		{
			mRifleGuns[0]->SetHiddenInGame(false);
			mRifleGuns[1]->SetHiddenInGame(true);
		}
	}
}


