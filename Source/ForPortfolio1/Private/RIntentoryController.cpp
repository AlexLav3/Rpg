// Fill out your copyright notice in the Description page of Project Settings.

#include "RIntentoryController.h"
#include "RInventoryDatabaseGameState.h"
#include "SPlayerCharacter.h"



ARIntentoryController::ARIntentoryController()
{
	InventorySlotLimit = 50;

}

bool ARIntentoryController::AddItemToInventoryByID(FName ID)
{
    ARInventoryDatabaseGameState* GameState = Cast<ARInventoryDatabaseGameState>(GetWorld()->GetGameState());
    UDataTable* ItemTable = GameState->GetItemDB();
    FURItemsPickedUp* ItemToAdd = ItemTable->FindRow<FURItemsPickedUp>(ID, "");

    if (ItemToAdd)
    {
        if (Inventory.Num() < InventorySlotLimit) {
            return true;
        }
        ReloadInventory();
    }
        return false;

}

void ARIntentoryController::Interact()
{

    if (CurrentInteractable)
    {
        CurrentInteractable->CheckInteract();
    }
}
