// Fill out your copyright notice in the Description page of Project Settings.


#include "Riffle.h"

#include "MetroCharacter.h"
#include "AssetTypeActions/AssetDefinition_SoundBase.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARiffle::ARiffle()
{
	Root= CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
 	Rifle = CreateDefaultSubobject<UStaticMeshComponent>("Rifle");
	Rifle->SetupAttachment(RootComponent);

	Box = CreateDefaultSubobject<UBoxComponent>("BoxComp");
	Box->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARiffle::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this,&ARiffle::OnOverlapBegin);
}

void ARiffle::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(TObjectPtr<AMetroCharacter> Player = CastChecked<AMetroCharacter>(OtherActor))
	{
		Player->SetRiffle(true);
		Player->SetEquip(true);
		Player->GetRifleGuns()[0]->SetHiddenInGame(false);
		UGameplayStatics::PlaySound2D(this,ShotSound);
		Destroy();
	}
}

