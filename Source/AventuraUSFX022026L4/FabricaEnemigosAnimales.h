
#pragma once

#include "CoreMinimal.h"
#include "FabricaEnemigos.h"
#include "FabricaEnemigosAnimales.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaEnemigosAnimales : public AFabricaEnemigos
{
    GENERATED_BODY()

public:

    // Sobrescribe los 4 metodos de la fabrica padre
    virtual AEnemigoTerrestre* CrearTerrestre(FVector Posicion) override;
    virtual AEnemigoAereo* CrearAereo(FVector Posicion) override;
    virtual AEnemigoAcuatico* CrearAcuatico(FVector Posicion) override;
    virtual AEnemigoSubterraneo* CrearSubterraneo(FVector Posicion) override;
};
