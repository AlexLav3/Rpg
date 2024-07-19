// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "RRunAwayTask.generated.h"

UCLASS()
class FORPORTFOLIO1_API UBTTask_RunAway : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_RunAway();

protected:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

