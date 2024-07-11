// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RInteractComponent.h"
#include "RGameplayInterface.h"
#include "RManualPickups.generated.h"

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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
