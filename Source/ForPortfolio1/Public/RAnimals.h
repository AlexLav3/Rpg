// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RAnimalsAiController.h"
#include "RAnimals.generated.h"

class UStaticMeshComponent; 
class UCapsuleComponent; 

UCLASS()
class FORPORTFOLIO1_API ARAnimals : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARAnimals();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
