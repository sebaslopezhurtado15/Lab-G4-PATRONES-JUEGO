
#include "FabricaEnemigosAnimales.h"
#include "EnemigoTerrestreAnimal.h"
#include "EnemigoAereoAnimal.h"
#include "EnemigoAcuaticoAnimal.h"
#include "EnemigoSubterraneoAnimal.h"
#include "Engine/World.h"

// Cada metodo crea un enemigo de la familia Animal

AEnemigoTerrestre* AFabricaEnemigosAnimales::CrearTerrestre(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoTerrestreAnimal>(Posicion, FRotator::ZeroRotator);
}

AEnemigoAereo* AFabricaEnemigosAnimales::CrearAereo(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoAereoAnimal>(Posicion, FRotator::ZeroRotator);
}

AEnemigoAcuatico* AFabricaEnemigosAnimales::CrearAcuatico(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoAcuaticoAnimal>(Posicion, FRotator::ZeroRotator);
}

AEnemigoSubterraneo* AFabricaEnemigosAnimales::CrearSubterraneo(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoSubterraneoAnimal>(Posicion, FRotator::ZeroRotator);
}
