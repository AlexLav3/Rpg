// Fill out your copyright notice in the Description page of Project Settings.


#include "RRunAwayTask.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

UBTTask_RunAway::UBTTask_RunAway()
{
    bNotifyTick = true;
    bNotifyTaskFinished = true;
    bCreateNodeInstance = false;
    NodeName = TEXT("Run Away");
}

EBTNodeResult::Type UBTTask_RunAway::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    AAIController* AIController = OwnerComp.GetAIOwner();
    if (AIController)
    {
        ACharacter* AICharacter = Cast<ACharacter>(AIController->GetPawn());
        if (AICharacter)
        {
            FVector PlayerLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(TEXT("PlayerLocation"));
            FVector AwayDirection = AICharacter->GetActorLocation() - PlayerLocation;
            AwayDirection.Normalize();

            FVector NewLocation = AICharacter->GetActorLocation() + AwayDirection * 600.0f; // Move 600 units away from player
            AIController->MoveToLocation(NewLocation);

            return EBTNodeResult::Succeeded;
        }
    }
    return EBTNodeResult::Failed;
}
