// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logging/LogMacros.h"
#include "GameFramework/Character.h"
#include "RInteractComponent.h"
#include "SPlayerCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UAnimMontage;
struct FInputActionValue;

class UPInterfaceComponent;
class URAttributesComponent;

UCLASS()
class FORPORTFOLIO1_API ASPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PauseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RunAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SniffAction;

	float NormalWalkSpeed; 

public:
	// Sets default values for this character's properties
	ASPlayerCharacter();

protected:

	UFUNCTION() /** Called for movement input */
	void Move(const FInputActionValue& Value);

	UFUNCTION()/** Called for looking input */
	void Look(const FInputActionValue& Value);
	UFUNCTION()
	void Run(const FInputActionValue& Value); 
	
	UFUNCTION()
    void StopRunning(const FInputActionValue& Value);

	FTimerHandle TimerHandle_EnableRunning;

	UFUNCTION()
	void EnableRunning();

	UFUNCTION()
   void HandleJump(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, Category = "Jump")
	UAnimMontage* JumpAnim;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	bool bIsRunning;

	bool bCanRun;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UFUNCTION()
	void StaminaChange(AActor* InstigatorActor, URAttributesComponent* OwningComp, float NewStamima, float DeltaTime);

	UFUNCTION()
	virtual void PostInitializeComponents() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	URAttributesComponent* AttributesComp;

	UPROPERTY(VisibleAnywhere)
	URInteractComponent* InteractionComp;

	// sniff for ambient, all potential tracks that are in "memory" 
	UFUNCTION()
	void Sniff(); 


};
