// Fill out your copyright notice in the Description page of Project Settings.


#include "MetroCharacter.h"

#include "EnhancedInputComponent.h"

AMetroCharacter::AMetroCharacter()
{
	mRiffleGuns.Reserve(3);
	for(int i =0;i<3;i++)
	{
		TObjectPtr<UStaticMeshComponent> riffle= CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("RiffleGun %d "),i) );
		riffle->SetupAttachment(GetMesh(),FName("GunHold"));
		mRiffleGuns.Add(riffle);
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

void AMetroCharacter::Equip()
{
	if(mbEquip)
	{
		if(mbRiffle)
		{
			mRiffleGuns[0]->SetHiddenInGame(true);
			mRiffleGuns[1]->SetHiddenInGame(false);
		}
		else
		{
			mRiffleGuns[0]->SetHiddenInGame(false);
			mRiffleGuns[1]->SetHiddenInGame(true);
		}
	}
}
