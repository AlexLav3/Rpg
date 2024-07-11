// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RInteractComponent.h"
#include "RItemsPickedUp.h"
#include "RGameplayInterface.h"
#include "RManualPickups.h"
#include "RIntentoryController.generated.h"

/**
 * 
 */

UCLASS()
class FORPORTFOLIO1_API ARIntentoryController : public APlayerController
{
	GENERATED_BODY()
	
    ARIntentoryController();

public: 

  
    UFUNCTION(BlueprintImplementableEvent)
    void ReloadInventory();

    UFUNCTION(BlueprintCallable, Category = "Utils")
    bool AddItemToInventoryByID(FName ID);

    UPROPERTY(VisibleAnywhere)
    URInteractComponent* CurrentInteractable;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    TArray<AActor*> Inventory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 InventorySlotLimit;

protected: 

    void Interact();

};
