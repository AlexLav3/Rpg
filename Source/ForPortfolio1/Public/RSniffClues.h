// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPlayerCharacter.h"
#include "RInteractComponent.h"
#include "RGameplayInterface.h"
#include "RSniffClues.generated.h"

class UStaticMeshComponent; 
class UCapsuleComponent; 

UCLASS()
class FORPORTFOLIO1_API ARSniffClues : public AActor, public IRGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARSniffClues();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComp;

	UFUNCTION()
	void Interact_Implementation(APawn* InstigatorPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
	void VisibilitySwitch();

	FTimerHandle TimerHandle_Visibility;

	virtual void Tick(float DeltaTime) override;

};
