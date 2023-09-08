// Fill out your copyright notice in the Description page of Project Settings.


#include "MetroCharacter.h"

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
