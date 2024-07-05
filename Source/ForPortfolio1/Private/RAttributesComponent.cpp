// Fill out your copyright notice in the Description page of Project Settings.


#include "RAttributesComponent.h"

// Sets default values for this component's properties
URAttributesComponent::URAttributesComponent()
{
	Health = 100;

}

bool URAttributesComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;

	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}

bool URAttributesComponent::bIsAlive() const
{
	return Health > 0.0f;
}
