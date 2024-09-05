// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RAnimalsAiController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

ARAnimalsAiController::ARAnimalsAiController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ARAnimalsAiController::BeginPlay()
{
    Super::BeginPlay();
    RunBehaviorTree(BehaviourTree);
}

void ARAnimalsAiController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    PlayerCharacter = UGameplayStatics::GetPlayerPawn(this, 0);

    if (PlayerCharacter) {
        PlayerLocation = PlayerCharacter->GetActorLocation();
    }
    FVector Animalocation = GetPawn()->GetActorLocation();
    float DistanceToPlayer = FVector::Distance(Animalocation, PlayerLocation);

    float RunningTreshold = 500.0f;
    if (DistanceToPlayer <= RunningTreshold)
    {
        OnPawnDetected();
    }
}    

void ARAnimalsAiController::OnPawnDetected()
{
   ANavigationData* NavData = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld())->GetDefaultNavDataInstance(FNavigationSystem::ECreateIfEmpty::Create);

    if (NavData)
    {
        FVector Origin = GetPawn()->GetActorLocation(); 
        float Radius = 1000.0f; 

        FNavLocation RandomLocation;
        bool bFoundLocation = UNavigationSystemV1::GetCurrent(GetWorld())->GetRandomReachablePointInRadius(Origin, Radius, RandomLocation, NavData);

        if (bFoundLocation)
        {
            RandomTargetLocation = RandomLocation.Location;
        }
    }
    GetBlackboardComponent()->SetValueAsVector("RunningTask", RandomTargetLocation);
}

