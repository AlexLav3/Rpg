// Fill out your copyright notice in the Description page of Project Settings.


#include "RManualPickups.h"
#include "GameFramework/PlayerController.h"
#include "RIntentoryController.h"

// Sets default values
ARManualPickups::ARManualPickups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComp->InitCapsuleSize(42.f, 96.0f);

	RootComponent = PickupMesh;

	CapsuleComp->SetupAttachment(PickupMesh);

    ItemID = FName("No ID");

	Name = "Interactable";
	Action = "interact";
}

// Called when the game starts or when spawned
void ARManualPickups::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARManualPickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARManualPickups::Interact_Implementation(APlayerController* Controller)
{
	ARIntentoryController* IController = Cast<ARIntentoryController>(Controller);

	IController->AddItemToInventoryByID(ItemID); 
	
	Destroy();
	
}

FName ARManualPickups::GetItemID()
{
	return ItemID;
}
