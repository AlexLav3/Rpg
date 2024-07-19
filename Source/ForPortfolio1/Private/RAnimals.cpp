// Fill out your copyright notice in the Description page of Project Settings.

#include "RAnimals.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ARAnimals::ARAnimals()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

