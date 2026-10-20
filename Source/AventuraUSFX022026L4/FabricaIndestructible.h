
#pragma once

#include "CoreMinimal.h"
#include "FabricaPlataforma.h"
#include "FabricaIndestructible.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaIndestructible : public AFabricaPlataforma
{
    GENERATED_BODY()

public:
    // Sobrescribe el metodo 
    virtual APlataforma* CrearPlataforma(FVector Posicion) override;
};
