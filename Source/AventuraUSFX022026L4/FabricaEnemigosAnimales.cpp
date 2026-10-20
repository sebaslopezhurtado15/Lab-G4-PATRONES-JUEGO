
#include "FabricaEnemigosAnimales.h"
#include "EnemigoTerrestreAnimal.h"
#include "EnemigoAereoAnimal.h"
#include "EnemigoAcuaticoAnimal.h"
#include "EnemigoSubterraneoAnimal.h"
#include "Engine/World.h"

// Cada metodo crea un enemigo de la familia Animal

AEnemigoTerrestre* AFabricaEnemigosAnimales::CrearTerrestre(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoTerrestreAnimal>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}

AEnemigoAereo* AFabricaEnemigosAnimales::CrearAereo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoAereoAnimal>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}

AEnemigoAcuatico* AFabricaEnemigosAnimales::CrearAcuatico(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoAcuaticoAnimal>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}

AEnemigoSubterraneo* AFabricaEnemigosAnimales::CrearSubterraneo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<AEnemigoSubterraneoAnimal>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}
