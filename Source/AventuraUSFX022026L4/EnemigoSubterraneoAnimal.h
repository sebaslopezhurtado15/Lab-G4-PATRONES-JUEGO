#pragma once

#include "CoreMinimal.h"
#include "EnemigoSubterraneo.h"
#include "EnemigoSubterraneoAnimal.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoSubterraneoAnimal : public AEnemigoSubterraneo
{
    GENERATED_BODY()

public:
    AEnemigoSubterraneoAnimal();

protected:
    // Malla visual del enemigo subterraneo animal.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaTopo;
};
