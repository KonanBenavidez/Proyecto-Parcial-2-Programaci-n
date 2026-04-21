
#include "puerta.h"

APuerta::APuerta()
{
    PrimaryActorTick.bCanEverTick = false;
}

void APuerta::BeginPlay()
{
    Super::BeginPlay();

   
    for (AAltar* Altar : AltarsToWatch)
    {
        if (Altar)
        {
       
            Altar->OnAltarActivated.AddDynamic(this, &APuerta::OnAltarActivated);
        }
    }
}

void APuerta::OnAltarActivated(AAltar* Altar)
{
    ActivatedCount++;

    UE_LOG(LogTemp, Warning, TEXT("Altares activados: %d / %d"), ActivatedCount, RequiredAltars);


    if (ActivatedCount >= RequiredAltars)
    {
        OpenGate();
    }
}

void APuerta::OpenGate()
{
    UE_LOG(LogTemp, Warning, TEXT("La puerta del templo se abre"));
    Destroy(); 
}