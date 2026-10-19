
#include "FabricaEnemigosAlienigenas.h"
#include "EnemigoTerrestreAlienigena.h"
#include "EnemigoAereoAlienigena.h"
#include "EnemigoAcuaticoAlienigena.h"
#include "EnemigoSubterraneoAlienigena.h"
#include "Engine/World.h"


// Crea los 4 enemigos de la familia Alienigena
AEnemigoTerrestre* AFabricaEnemigosAlienigenas::CrearTerrestre(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoTerrestreAlienigena>(Posicion, FRotator::ZeroRotator);
}

AEnemigoAereo* AFabricaEnemigosAlienigenas::CrearAereo(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoAereoAlienigena>(Posicion, FRotator::ZeroRotator);
}

AEnemigoAcuatico* AFabricaEnemigosAlienigenas::CrearAcuatico(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoAcuaticoAlienigena>(Posicion, FRotator::ZeroRotator);
}

AEnemigoSubterraneo* AFabricaEnemigosAlienigenas::CrearSubterraneo(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<AEnemigoSubterraneoAlienigena>(Posicion, FRotator::ZeroRotator);
}
