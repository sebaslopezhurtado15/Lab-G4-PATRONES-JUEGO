#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EnemigoAereoAlienigena.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoAereoAlienigena : public AEnemigoAereo
{
    GENERATED_BODY()

public:
    AEnemigoAereoAlienigena();

protected:
    // Malla visual del enemigo aereo alienigena.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaDron;
};
