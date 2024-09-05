// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Kismet/GameplayStatics.h>
#include "RAnimalsAiController.generated.h"

class UBehaviorTree;

UCLASS()
class FORPORTFOLIO1_API ARAnimalsAiController : public AAIController
{
    GENERATED_BODY()

public:
    ARAnimalsAiController();

protected:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(EditDefaultsOnly, Category = "Bt")
    UBehaviorTree* BehaviourTree;


    UFUNCTION()
    void OnPawnDetected();

    FVector PlayerLocation;
    FVector RandomTargetLocation;
    float SearchRadius = 500;

private:
    APawn* PlayerCharacter;
};
