// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Metroid_MiniGame/Metroid_MiniGameCharacter.h"
#include "MetroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class METROID_MINIGAME_API AMetroCharacter : public AMetroid_MiniGameCharacter
{
	GENERATED_BODY()
public:
	AMetroCharacter();
protected:
	virtual void BeginPlay() override;

private:


private:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Instanced,Category="Components",meta = (AllowPrivateAccess = true))
	TArray<TObjectPtr<UStaticMeshComponent>> mRiffleGuns;

};
