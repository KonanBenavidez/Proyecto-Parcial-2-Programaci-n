
#include "Altar.h"
#include "Components/SphereComponent.h"
#include "TimerManager.h"
#include "Engine/Engine.h" 

AAltar::AAltar()
{
	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
	InteractionSphere->SetSphereRadius(200.f);
	RootComponent = InteractionSphere;
}

void AAltar::TryActivate(ACharacter* Player)
{
	
	if (bIsActivated) return;

	
	GetWorldTimerManager().SetTimer(
		ActivationTimerHandle,
		this,
		&AAltar::FinishActivation,
		ActivationTime,
		false 
	);

	UE_LOG(LogTemp, Warning, TEXT("Altar activándose..."));
}

void AAltar::FinishActivation()
{
	bIsActivated = true;
	OnAltarActivated.Broadcast(this);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green,
			FString::Printf(TEXT("Altar activado: %s"), *GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("Altar activado"));
}

void AAltar::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Altar listo: %s"), *GetName());
}