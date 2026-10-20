
#include "FabricaEnemigosAlienigenas.h"
#include "EnemigoTerrestreAlienigena.h"
#include "EnemigoAereoAlienigena.h"
#include "EnemigoAcuaticoAlienigena.h"
#include "EnemigoSubterraneoAlienigena.h"
#include "Engine/World.h"

// Crear enemigo terrestre alienigena
AEnemigoTerrestre* AFabricaEnemigosAlienigenas::CrearTerrestre(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoTerrestreAlienigena* Enemigo = Mundo->SpawnActor<AEnemigoTerrestreAlienigena>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}

// Crear enemigo aereo alienigena
AEnemigoAereo* AFabricaEnemigosAlienigenas::CrearAereo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoAereoAlienigena* Enemigo = Mundo->SpawnActor<AEnemigoAereoAlienigena>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}

// Crear enemigo acuatico alienigena
AEnemigoAcuatico* AFabricaEnemigosAlienigenas::CrearAcuatico(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoAcuaticoAlienigena* Enemigo = Mundo->SpawnActor<AEnemigoAcuaticoAlienigena>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}

// Crear enemigo subterraneo alienigena
AEnemigoSubterraneo* AFabricaEnemigosAlienigenas::CrearSubterraneo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoSubterraneoAlienigena* Enemigo = Mundo->SpawnActor<AEnemigoSubterraneoAlienigena>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}
