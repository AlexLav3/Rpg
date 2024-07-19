
#include "RAnimalsAiController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

ARAnimalsAiController::ARAnimalsAiController()
{
    PrimaryActorTick.bCanEverTick = true;

    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

    SightConfig->SightRadius = 2000.0f;
    SightConfig->LoseSightRadius = SightConfig->SightRadius + 50.0f;
    SightConfig->PeripheralVisionAngleDegrees = 90.0f;
    SightConfig->SetMaxAge(5.0f);

    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

    AIPerceptionComponent->ConfigureSense(*SightConfig);
    AIPerceptionComponent->SetDominantSense(*SightConfig->GetSenseImplementation());

    AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ARAnimalsAiController::OnPawnDetected);
}

void ARAnimalsAiController::BeginPlay()
{
    Super::BeginPlay();
}

void ARAnimalsAiController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ARAnimalsAiController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
    for (AActor* Actor : DetectedPawns)
    {
        ACharacter* DetectedCharacter = Cast<ACharacter>(Actor);
        if (DetectedCharacter && DetectedCharacter->IsPlayerControlled())
        {
            PlayerCharacter = DetectedCharacter;
            PlayerLocation = PlayerCharacter->GetActorLocation();
      
            break;
        }
    }
}

