// Fill out your copyright notice in the Description page of Project Settings.


#include "MetroPlayerController.h"

#include "MetroCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

AMetroPlayerController::AMetroPlayerController()
{
	mYLock = 500.0f;
	bShowMouseCursor = true;
}

void AMetroPlayerController::BeginPlay()
{
	Super::BeginPlay();
	MetroPlayer = Cast<AMetroCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
}

void AMetroPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	DeprojectMousePositionToWorld(mWorldLocation,mWorldDirection);
	
	GetAimLoc(MetroPlayer,MetroPlayer->GetFollowCamera(),mWorldDirection,mYLock,mAimLoc);
	
}

bool AMetroPlayerController::GetAimLoc(const AMetroCharacter* MPlayer, const UCameraComponent* Cam,
	const FVector& WorldDir, const float& YLock, FVector& AimLoc)
{
	if(!IsValid(MPlayer)&&!IsValid(Cam))
	{
		return false;
	}
	
	FVector CamLoc = Cam->GetComponentLocation();
	FVector CamRotForward = Cam->GetComponentRotation().Vector();
	
	FVector CamToPlayer = MPlayer->GetActorLocation() - CamLoc;
	CamToPlayer.Z = 0;
	float CamToPlayerLength = CamToPlayer.Length();

	
	float CamDotMouseDir = FVector::DotProduct(CamRotForward,WorldDir);
	float Theta = FMath::Acos(CamDotMouseDir);

	float HypotenuseLength = CamToPlayerLength/FMath::Cos(Theta);

	FVector HypotenuseVector = WorldDir*HypotenuseLength;

	
	AimLoc = HypotenuseVector + CamLoc;
	AimLoc.Y =YLock;
	
	UE_LOG(LogTemp,Display,TEXT("%s"),*AimLoc.ToString());
	GEngine->AddOnScreenDebugMessage(-1,0.1f,FColor::Yellow,FString::Printf(TEXT("Aim : %s"),*AimLoc.ToString()));
	
	DrawDebugSphere(GetWorld(),AimLoc,50.0f,12.0f,FColor::Green,false,5.0f);
	return true;
}


