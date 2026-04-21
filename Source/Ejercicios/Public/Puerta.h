
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Altar.h"
#include "Puerta.generated.h"

UCLASS()
class EJERCICIOS_API APuerta : public AActor
{
	GENERATED_BODY()

public:
	APuerta();

protected:
	virtual void BeginPlay() override;

private:
	
	UPROPERTY(EditAnywhere)
	int32 RequiredAltars = 3;

	int32 ActivatedCount = 0;

	
	UPROPERTY(EditAnywhere)
	TArray<AAltar*> AltarsToWatch;

	
	UFUNCTION()
	void OnAltarActivated(AAltar* Altar);

	void OpenGate();
};