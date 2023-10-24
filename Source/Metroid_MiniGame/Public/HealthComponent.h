// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class METROID_MINIGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void ActiveInvisibleTime();
private:
	UPROPERTY(EditAnywhere)
	float MaxHealth = 100.0f;
	
	float Health = 0.0f;
	

	bool isInvisible;
	
	FTimerHandle InvisibleTimer;
	FTimerDelegate TimerDel;
	UFUNCTION()
	void DamageTaken(AActor* DamagedActor,float Damage, const UDamageType* DamageType,class AController* Instigator,AActor* DamageCauser);
		
};
