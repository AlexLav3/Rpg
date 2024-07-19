// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "RAnimalsAiController.generated.h"

UCLASS()
class FORPORTFOLIO1_API ARAnimalsAiController : public AAIController
{
    GENERATED_BODY()

public:
    ARAnimalsAiController();

protected:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    class UAIPerceptionComponent* AIPerceptionComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    class UAISenseConfig_Sight* SightConfig;

    UFUNCTION()
    void OnPawnDetected(const TArray<AActor*>& DetectedPawns);

    FVector PlayerLocation;

private:
    ACharacter* PlayerCharacter;
};
