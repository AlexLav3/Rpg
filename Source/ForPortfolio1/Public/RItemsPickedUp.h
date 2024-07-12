// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "RItemsPickedUp.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FORPORTFOLIO1_API FURItemsPickedUp : public FTableRowBase
{
	GENERATED_BODY()

    FURItemsPickedUp(); 

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ItemID;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;


    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Value;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UTexture2D* Thumbnail;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    bool operator==(const FURItemsPickedUp& OtherItem) const
    {
        if (ItemID == OtherItem.ItemID) {
            return true;
        }
        return false;
    }
    
};
 