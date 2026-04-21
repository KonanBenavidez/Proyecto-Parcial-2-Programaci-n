

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Altar.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAltarActivated, AAltar*, Altar);

UCLASS()
class EJERCICIOS_API AAltar : public AActor
{
    GENERATED_BODY()

public:
    AAltar();

  
    UPROPERTY(BlueprintAssignable)
    FOnAltarActivated OnAltarActivated;


    void TryActivate(ACharacter* Player);

    bool bIsActivated = false;

protected:
    virtual void BeginPlay() override;

 
    UPROPERTY(EditAnywhere)
    float ActivationTime = 3.0f;

private:
    FTimerHandle ActivationTimerHandle;

    void FinishActivation();


    UPROPERTY(VisibleAnywhere)
    class USphereComponent* InteractionSphere;
};