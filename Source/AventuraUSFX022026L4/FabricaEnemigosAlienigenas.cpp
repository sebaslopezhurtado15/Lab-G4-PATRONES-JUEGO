
#include "FabricaEnemigosAlienigenas.h"
#include "EnemigoTerrestreAlienigena.h"
#include "EnemigoAereoAlienigena.h"
#include "EnemigoAcuaticoAlienigena.h"
#include "EnemigoSubterraneoAlienigena.h"
#include "Engine/World.h"


// Crea los 4 enemigos de la familia Alienigena
AEnemigoTerrestre* AFabricaEnemigosAlienigenas::CrearTerrestre(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoTerrestreAlienigena>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}

AEnemigoAereo* AFabricaEnemigosAlienigenas::CrearAereo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoAereoAlienigena>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}

AEnemigoAcuatico* AFabricaEnemigosAlienigenas::CrearAcuatico(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoAcuaticoAlienigena>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}

AEnemigoSubterraneo* AFabricaEnemigosAlienigenas::CrearSubterraneo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoSubterraneoAlienigena>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}
