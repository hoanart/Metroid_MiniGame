// Fill out your copyright notice in the Description page of Project Settings.


#include "MetroCharacter.h"

#include "EnhancedInputComponent.h"
#include "MetroPlayerController.h"
#include "RifleProjectile.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

AMetroCharacter::AMetroCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	
	
	mProjectilePosition = CreateDefaultSubobject<USceneComponent>("ProjectilePosition");
	mProjectilePosition->SetupAttachment(RootComponent);
	
	mRifleGunHold= CreateDefaultSubobject<UStaticMeshComponent>(*FString::Printf(TEXT("RiffleGun1")) );
	mRifleGunHold->SetupAttachment(GetMesh(),FName("GunHold"));
	mSphereComp = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	mSphereComp->SetupAttachment(mRifleGunHold);
	
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
		EnhancedInputComponent->BindAction(FireAction,ETriggerEvent::Triggered,this,&AMetroCharacter::Fire);
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

const bool& AMetroCharacter::IsInAir() const
{
	return mbInAir;
}

void AMetroCharacter::SetInAir(const bool& bInAir)
{
	mbInAir = bInAir;
}

const FVector& AMetroCharacter::GetGunOffset() const
{
	return mGunOffset;
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

void AMetroCharacter::Fire()
{
	if(mbRiffle&&!mbInAir)
	{
		UGameplayStatics::PlaySound2D(this,ShotSound);

		FActorSpawnParameters Params;
		Params.Owner = this;
		Params.Instigator = GetInstigator();
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

		FVector Loc = mSphereComp->GetComponentLocation();
		FRotator Rot = mProjectilePosition->GetComponentRotation();
		Rot.Pitch+= mRifleGunHold->GetComponentRotation().Pitch;
			//Cast<AMetroPlayerController> (UGameplayStatics::GetPlayerController(this,0))->GetAimPitch()
		 Loc += Rot.RotateVector(GetGunOffset());
		FTransform Trans = FTransform(Rot,Loc,FVector(1.0f,1.0f,1.0f));
		GEngine->AddOnScreenDebugMessage(-1,0.1f,FColor::Yellow,FString::Printf(TEXT("Rot : %s"),*Rot.ToString()));
		//UE_LOG(LogTemp,Display,TEXT("bullet rot %s"),*Rot.ToString());
		TObjectPtr<ARifleProjectile> BulletSpawned = GetWorld()->SpawnActor<ARifleProjectile>(mRifleProjectileClass,Trans,Params);
		
	}
}


