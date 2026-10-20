#pragma once

#include "CoreMinimal.h"
#include "EnemigoAcuatico.h"
#include "EnemigoAcuaticoAlienigena.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoAcuaticoAlienigena : public AEnemigoAcuatico
{
    GENERATED_BODY()

public:
    AEnemigoAcuaticoAlienigena();

protected:
    // Malla visual del enemigo acuatico alienigena.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaMedusa;
};
