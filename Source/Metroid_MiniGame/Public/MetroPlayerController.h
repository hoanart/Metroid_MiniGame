// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MetroPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API AMetroPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AMetroPlayerController();
	virtual void BeginPlay() override;
	
private:
	virtual void PlayerTick(float DeltaTime) override;

public:
	bool GetAimLoc(const class AMetroCharacter* Player,const class UCameraComponent* Cam, const FVector& WorldDir, const float& YLoc, FVector& AimLoc);
private:
	UPROPERTY(VisibleAnywhere,Category="Mouse")
	float mMouseX;
	UPROPERTY(VisibleAnywhere,Category="Mouse")
	float mMouseY;
	
	UPROPERTY(VisibleAnywhere,Category="Mouse")
	float mYLock;
	
	UPROPERTY(VisibleAnywhere,Category="Mouse")
	FVector mWorldLocation;
	UPROPERTY(VisibleAnywhere,Category="Mouse")
	FVector mWorldDirection;

	UPROPERTY(VisibleAnywhere,Category="Aim")
	FVector mAimLoc;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player", meta =(AllowPrivateAccess = true))
	TObjectPtr<class AMetroCharacter> MetroPlayer;
};
