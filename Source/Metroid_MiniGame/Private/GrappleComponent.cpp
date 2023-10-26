// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleComponent.h"

#include "MetroPlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UGrappleComponent::UGrappleComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrappleComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrappleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGrappleComponent::TracePoint()
{
	FVector StartLoc = GetOwner()->GetActorLocation();
	

	FHitResult HitResult;

	FCollisionQueryParams TraceParams(FName(TEXT("GrapplePoint")));
	TObjectPtr<AMetroPlayerController> MPController = Cast<AMetroPlayerController>( UGameplayStatics::GetPlayerController(this,0));
	FVector EndLoc = MPController->GetAimLoc();
	
	if(MPController)
	{
		//DrawDebugSphere(GetWorld(),MPController->GetAimLoc(),50.0f,12.0f,FColor::Green,false,5.0f);
		//GetWorld()->LineTraceSingleByObjectType(HitResult,StartLoc,EndLoc,ECC_GameTraceChannel1, TraceParams)
		if(GetWorld()->LineTraceSingleByObjectType(HitResult,StartLoc,EndLoc,ECC_WorldStatic))
		{
			FVector ImpactPoint = HitResult.ImpactPoint;

			DrawDebugSphere(GetWorld(),MPController->GetAimLoc(),50.0f,12.0f,FColor::Green,false,5.0f);
			DrawDebugSphere(GetWorld(), ImpactPoint,20.0f,10.0f,FColor::Red,false,0.5f,0,1);
		
		}
	}

	
	
}

