// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RInteractComponent.h"
#include "Components/CapsuleComponent.h"
#include "RGameplayInterface.h"
#include "RManualPickups.generated.h"

class UStaticMeshComponent; 
class UCapsuleComponent; 

UCLASS()
class FORPORTFOLIO1_API ARManualPickups : public AActor, public IRGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARManualPickups();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemID;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Interact_Implementation(APawn* InstigatorPawn);

	UPROPERTY(EditDefaultsOnly)
	FString Name;

	UPROPERTY(EditDefaultsOnly)
	FString Action;

};
