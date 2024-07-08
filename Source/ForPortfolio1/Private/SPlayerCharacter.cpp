// Fill out your copyright notice in the Description page of Project Settings.


#include "SPlayerCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RAttributesComponent.h"
#include "InputActionValue.h"

// Sets default values
ASPlayerCharacter::ASPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 200.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;


	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;
	CameraBoom->bUsePawnControlRotation = false;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	AttributesComp = CreateDefaultSubobject<URAttributesComponent>(TEXT("AttributesComponent"));

	NormalWalkSpeed= 400.f;
	bCanRun = true;
	bIsRunning = false;
}

void ASPlayerCharacter::Move(const FInputActionValue& Value)
{//  Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ASPlayerCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		//  yaw and pitch input 
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ASPlayerCharacter::HandleJump(const FInputActionValue& Value)
{
	Super::Jump(); 

	if (JumpAnim)
	{
		UE_LOG(LogTemp, Log, TEXT("Playing Jump Animation"));
		PlayAnimMontage(JumpAnim);
	}
}

void ASPlayerCharacter::Run(const FInputActionValue& Value)
{

	if (bCanRun)
	{
		GetCharacterMovement()->MaxWalkSpeed = 2011.f;
		bIsRunning = true;
	}
	else
	{
		StopRunning(FInputActionValue());
	}

}

// Called when the game starts or when spawned
void ASPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
}

void ASPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{


	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ASPlayerCharacter::HandleJump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ASPlayerCharacter::Move);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ASPlayerCharacter::Look);

		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Started, this, &ASPlayerCharacter::Run);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Completed, this, &ASPlayerCharacter::StopRunning);

		EnhancedInputComponent->BindAction(SniffAction, ETriggerEvent::Completed, this, &ASPlayerCharacter::Sniff);

	}
	else
	{
		//UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}
void ASPlayerCharacter::EnableRunning()
{
	AttributesComp->Stamina = 100; 
	bCanRun = true; 
	
}

void ASPlayerCharacter::StaminaChange(AActor* InstigatorActor, URAttributesComponent* OwningComp, float NewStamima, float DeltaTime)
{
   AttributesComp->ModifyStamina(-30.f * DeltaTime);

	if (AttributesComp->Stamina <= 0)
	{
	bCanRun = false;
	StopRunning(FInputActionValue());
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_EnableRunning, this, &ASPlayerCharacter::EnableRunning, 5.f, false);
	}

}
void ASPlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
}

// Called every frame
void ASPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsRunning) {
		StaminaChange(this, AttributesComp, AttributesComp->Stamina, DeltaTime);
	}
}


void ASPlayerCharacter::StopRunning(const FInputActionValue& Value)
{   
	bIsRunning = false;
	GetCharacterMovement()->MaxWalkSpeed = NormalWalkSpeed; // Reset to normal walk speed
	
}

//abilities: 

void ASPlayerCharacter::Sniff()
{

}