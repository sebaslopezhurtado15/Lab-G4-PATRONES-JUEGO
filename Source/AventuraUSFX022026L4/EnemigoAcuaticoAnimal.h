#pragma once

#include "CoreMinimal.h"
#include "EnemigoAcuatico.h"
#include "EnemigoAcuaticoAnimal.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoAcuaticoAnimal : public AEnemigoAcuatico
{
    GENERATED_BODY()

public:
    AEnemigoAcuaticoAnimal();

protected:
    // Malla visual del enemigo acuatico animal.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaPez;
};
