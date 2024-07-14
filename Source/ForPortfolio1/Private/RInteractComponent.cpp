// Fill out your copyright notice in the Description page of Project Settings.

#include "RInteractComponent.h"
#include "DrawDebugHelpers.h" 
#include "RGameplayInterface.h"

// Sets default values for this component's properties
URInteractComponent::URInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void URInteractComponent::CheckInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();
	
	FVector EyeLocation;
	FRotator EyeRotation;

	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector End = EyeLocation + (EyeRotation.Vector() * 1000);

	TArray<FHitResult> Hits;

	float Radius = 30.0f;

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(MyOwner);

	FCollisionShape Shape;
	Shape.SetSphere(Radius);

	bool bBlockingHit = GetWorld()->SweepMultiByObjectType(Hits, EyeLocation, End, FQuat::Identity, ObjectQueryParams, Shape);

	FColor LineColor = bBlockingHit ? FColor::Green : FColor::Red;

	TArray<AActor*> OverlappingActors;

	for (const FHitResult Hit : Hits)
	{
		AActor* HitActor = Hit.GetActor();

		if (HitActor)
		{
			if (HitActor->Implements<URGameplayInterface>())
			{
				APawn* MyPawn = Cast<APawn>(MyOwner);
				IRGameplayInterface::Execute_Interact(HitActor, GetWorld()->GetFirstPlayerController());
				break; // Exit after first interaction
			}
		}
	}
	//debug: 
/*	DrawDebugLine(GetWorld(), EyeLocation, End, LineColor, false, 2.0f, 0, 2.0f);

	// Debugging: Draw the sphere for the sweep
	DrawDebugSphere(GetWorld(), EyeLocation, Radius, 32, LineColor, false, 2.0f);
	DrawDebugSphere(GetWorld(), End, Radius, 32, LineColor, false, 2.0f);*/
}


// Called when the game starts
void URInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

