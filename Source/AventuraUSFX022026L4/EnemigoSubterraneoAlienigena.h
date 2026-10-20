#pragma once

#include "CoreMinimal.h"
#include "EnemigoSubterraneo.h"
#include "EnemigoSubterraneoAlienigena.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoSubterraneoAlienigena : public AEnemigoSubterraneo
{
    GENERATED_BODY()

public:
    AEnemigoSubterraneoAlienigena();

protected:
    // Malla visual del enemigo subterraneo alienigena.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaTaladro;
};
