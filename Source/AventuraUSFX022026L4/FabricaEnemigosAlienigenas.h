
#pragma once

#include "CoreMinimal.h"
#include "FabricaEnemigos.h"
#include "FabricaEnemigosAlienigenas.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaEnemigosAlienigenas : public AFabricaEnemigos
{
    GENERATED_BODY()

public:
    // Sobrescribe los 4 metodos para crear enemigos alienigenas
    virtual AEnemigoTerrestre* CrearTerrestre(FVector Posicion) override;
    virtual AEnemigoAereo* CrearAereo(FVector Posicion) override;
    virtual AEnemigoAcuatico* CrearAcuatico(FVector Posicion) override;
    virtual AEnemigoSubterraneo* CrearSubterraneo(FVector Posicion) override;
};
