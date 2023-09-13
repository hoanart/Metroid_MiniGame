// Fill out your copyright notice in the Description page of Project Settings.


#include "RifleProjectile.h"

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARifleProjectile::ARifleProjectile()
{
 	mProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileComp");
	
	mSphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = mSphereComp;
	mCylinder = CreateDefaultSubobject<UStaticMeshComponent>("Cylinder");
	mCylinder->SetupAttachment(RootComponent);
	
	mExplosionParticle = CreateDefaultSubobject<UParticleSystemComponent>("ExplosionParticle");
	mExplosionParticle->SetupAttachment(RootComponent);
	
	mMuzzleParticle = CreateDefaultSubobject<UParticleSystemComponent>("MuzzleParticle");
	mMuzzleParticle->SetupAttachment(RootComponent);
	
	mExplosionCue = CreateDefaultSubobject<UAudioComponent>("ExplosionCue");
	mExplosionCue->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARifleProjectile::BeginPlay()
{
	Super::BeginPlay();
	mSphereComp->OnComponentHit.AddDynamic(this,&ARifleProjectile::OnHit);
	
}

void ARifleProjectile::OnHit(UPrimitiveComponent* HitComponent,
                             AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(OtherActor!= this)
	{
		
		mExplosionParticle->Activate(true);
		mExplosionCue->Activate(true);
		SetLifeSpan(0.06f);
	}

}


