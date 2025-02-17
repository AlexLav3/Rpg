// Fill out your copyright notice in the Description page of Project Settings.

#include "RSniffClues.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PlayerController.h"


// Sets default values
ARSniffClues::ARSniffClues()
{
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComp->InitCapsuleSize(42.f, 96.0f);

	RootComponent = BaseMesh;

	CapsuleComp->SetupAttachment(BaseMesh);


	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CapsuleComp->SetCollisionResponseToAllChannels(ECR_Overlap);
	CapsuleComp->SetGenerateOverlapEvents(true);
	BaseMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BaseMesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Overlap);

}

// Called when the game starts or when spawned
void ARSniffClues::BeginPlay()
{
	Super::BeginPlay();

	SetActorHiddenInGame(true);
	SetActorEnableCollision(true);
  
}



void ARSniffClues::VisibilitySwitch()
{
	SetActorHiddenInGame(true);
	
}


void ARSniffClues::Interact_Implementation(APlayerController* Controller)
{
	UE_LOG(LogTemp, Warning, TEXT("Interact_Implementation called"));

	ARIntentoryController* IController = Cast<ARIntentoryController>(Controller);

	SetActorHiddenInGame(false);

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Visibility, this, &ARSniffClues::VisibilitySwitch, 5.f, false);
}

// Called every frame
void ARSniffClues::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}