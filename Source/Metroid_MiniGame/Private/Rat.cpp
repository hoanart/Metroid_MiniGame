// Fill out your copyright notice in the Description page of Project Settings.


#include "Rat.h"

#include "HealthComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

ARat::ARat()
{
	HeadSphere = CreateDefaultSubobject<USphereComponent>("HeadSphereComp");
	HeadSphere->SetupAttachment(GetMesh(),FName("Head_MSocket"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
}

void ARat::BeginPlay()
{
	Super::BeginPlay();
	HeadSphere->OnComponentHit.AddDynamic(this,&ARat::OnHit);
}

void ARat::Attack( )
{
	Super::Attack();
}

void ARat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARat::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	Super::OnHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
	const TObjectPtr<ACharacter> Player = UGameplayStatics::GetPlayerCharacter(GetWorld(),0);
	
	if(IsValid(OtherActor)&&OtherActor == CastChecked<AActor>(Player))
	{
		UE_LOG(LogTemp,Warning,TEXT("Hit"));
		UGameplayStatics::ApplyDamage(OtherActor,20,GetOwner()->GetInstigatorController(),this,UDamageType::StaticClass());
	}
}
