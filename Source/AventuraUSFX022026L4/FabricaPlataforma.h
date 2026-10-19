
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaPlataforma.generated.h"

class APlataforma;

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaPlataforma : public AActor
{
    GENERATED_BODY()

public:
    AFabricaPlataforma();

    // Metodo creador que sobrescribiran las fabricas hijas
    virtual APlataforma* CrearPlataforma(FVector Posicion)
        PURE_VIRTUAL(AFabricaPlataforma::CrearPlataforma, return nullptr;);
};
