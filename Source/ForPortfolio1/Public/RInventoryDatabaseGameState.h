// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "RInventoryDatabaseGameState.generated.h"

/**
 * 
 */
UCLASS()
class FORPORTFOLIO1_API ARInventoryDatabaseGameState : public AGameStateBase
{
	GENERATED_BODY()


	ARInventoryDatabaseGameState(); 

public: 

	UDataTable* GetItemDB() const;

	UPROPERTY(EditDefaultsOnly)
	class UDataTable* ItemDB;
};
