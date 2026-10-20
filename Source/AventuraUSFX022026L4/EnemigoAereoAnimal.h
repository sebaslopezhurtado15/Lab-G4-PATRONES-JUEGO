#pragma once

#include "CoreMinimal.h"
#include "EnemigoAereo.h"
#include "EnemigoAereoAnimal.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoAereoAnimal : public AEnemigoAereo
{
    GENERATED_BODY()

public:
    AEnemigoAereoAnimal();

protected:
    // Malla visual del enemigo aereo animal.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaAve;
};
