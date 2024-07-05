// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RAttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstrigatorActor, URAttributesComponent*, OwningComp, float, NewHealth, float, Delta);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FStaminaChange, AActor*, InstrigatorActor, URAttributesComponent*, OwningComp, float, NewStamina, float, DeltaTime);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORPORTFOLIO1_API URAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URAttributesComponent();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Health;

public:	

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
	float Stamina;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FStaminaChange FStaminaChange;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	bool ApplyHealthChange(float Delta);

	UFUNCTION(BlueprintCallable)
	bool bIsAlive() const;

	UFUNCTION(BlueprintCallable)
	bool ModifyStamina(float Delta);
};
