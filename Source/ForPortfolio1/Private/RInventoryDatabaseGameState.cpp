// Fill out your copyright notice in the Description page of Project Settings.


#include "RInventoryDatabaseGameState.h"

ARInventoryDatabaseGameState::ARInventoryDatabaseGameState() {

    static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(TEXT("DataTable'/Game/RpgFoxOther/Data/ItemDB.ItemDB'"));
    if (BP_ItemDB.Succeeded())
    {
        ItemDB = BP_ItemDB.Object;
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load ItemDB"));
        ItemDB = nullptr;
    }
}

UDataTable* ARInventoryDatabaseGameState::GetItemDB() const
{
	return ItemDB;
}
