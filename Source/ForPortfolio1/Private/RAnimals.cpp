// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/CapsuleComponent.h"
#include "RAnimals.h"

// Sets default values
ARAnimals::ARAnimals()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AnimalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComp->InitCapsuleSize(42.f, 96.0f);

	RootComponent = AnimalMesh;

	CapsuleComp->SetupAttachment(AnimalMesh);

}

// Called when the game starts or when spawned
void ARAnimals::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARAnimals::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARAnimals::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

