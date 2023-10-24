// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	Health = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this,&UHealthComponent::DamageTaken);
	//TimerDel.BindUFunction(this,"Invisible")
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::ActiveInvisibleTime()
{
	isInvisible = false;
	
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                   AController* Instigator, AActor* DamageCauser)
{
	if(Damage<=0.0f)
	{
		return;
	}
	if(!isInvisible)
	{
		Health-=Damage;
		isInvisible = true;
		GetWorld()->GetTimerManager().ClearTimer(InvisibleTimer);
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(InvisibleTimer,this,&UHealthComponent::ActiveInvisibleTime,0.25f,false);
	}
	

	// if(Health<=0.0f&&ToonTanksGameMode)
	// {
	// 	ToonTanksGameMode->ActorDied(DamagedActor);
	// }
	UE_LOG(LogTemp,Warning,TEXT("Health: %f"),Health);
}

