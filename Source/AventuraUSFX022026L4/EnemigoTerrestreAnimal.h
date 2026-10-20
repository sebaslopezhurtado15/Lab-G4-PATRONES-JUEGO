
#pragma once

#include "CoreMinimal.h"
#include "EnemigoTerrestre.h"
#include "EnemigoTerrestreAnimal.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigoTerrestreAnimal : public AEnemigoTerrestre
{
    GENERATED_BODY()

public:
    AEnemigoTerrestreAnimal();

protected:

    // Malla visual del enemigo terrestre animal
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
        UStaticMeshComponent* MallaZorro;
};
