// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Riffle.generated.h"

UCLASS()
class METROID_MINIGAME_API ARiffle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARiffle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor,class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

private:
	
private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gun", meta =(AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> Rifle;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gun", meta =(AllowPrivateAccess = true))
	TObjectPtr<class UBoxComponent> Box;
	UPROPERTY(EditAnywhere, Category = "Gun")
	TObjectPtr<class USoundBase> ShotSound;
	
};
