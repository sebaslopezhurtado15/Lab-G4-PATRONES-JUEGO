#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h"
#include "EnemigoTerrestreAlienigena.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoTerrestreAlienigena : public AEnemigoTerrestre
{
    GENERATED_BODY()

public:
    AEnemigoTerrestreAlienigena();

protected:
    // Malla visual del enemigo terrestre alienigena.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
    UStaticMeshComponent* MallaGuardian;
};
