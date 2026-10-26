
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaEnemigos.generated.h"

//Declaracion antesedida
class AEnemigoTerrestre;
class AEnemigoAereo;
class AEnemigoAcuatico;
class AEnemigoSubterraneo;

UCLASS()
class AVENTURAUSFX022026L4_API AFabricaEnemigos : public AActor
{
    GENERATED_BODY()

public:
    AFabricaEnemigos();

    // Metodos de creacion que implementaran las fabricas hijas
    virtual AEnemigoTerrestre* CrearTerrestre(FVector Posicion)
        PURE_VIRTUAL(AFabricaEnemigos::CrearTerrestre, return nullptr;);

    virtual AEnemigoAereo* CrearAereo(FVector Posicion)
        PURE_VIRTUAL(AFabricaEnemigos::CrearAereo, return nullptr;);

    virtual AEnemigoAcuatico* CrearAcuatico(FVector Posicion)
        PURE_VIRTUAL(AFabricaEnemigos::CrearAcuatico, return nullptr;);

    virtual AEnemigoSubterraneo* CrearSubterraneo(FVector Posicion)
        PURE_VIRTUAL(AFabricaEnemigos::CrearSubterraneo, return nullptr;);
};
