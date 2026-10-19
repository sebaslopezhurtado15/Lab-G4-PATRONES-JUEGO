
#pragma once

#include "CoreMinimal.h"
#include "FabricaPlataforma.h"
#include "FabricaDestructible.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaDestructible : public AFabricaPlataforma
{
    GENERATED_BODY()

public:
    // Sobrescribe el metodo creador de la fabrica padre
    virtual APlataforma* CrearPlataforma(FVector Posicion) override;
};
