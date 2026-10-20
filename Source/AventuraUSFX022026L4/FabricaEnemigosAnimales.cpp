
#include "FabricaEnemigosAnimales.h"
#include "EnemigoTerrestreAnimal.h"
#include "EnemigoAereoAnimal.h"
#include "EnemigoAcuaticoAnimal.h"
#include "EnemigoSubterraneoAnimal.h"
#include "Engine/World.h"

// Crear enemigo terrestre animal
AEnemigoTerrestre* AFabricaEnemigosAnimales::CrearTerrestre(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoTerrestreAnimal* Enemigo = Mundo->SpawnActor<AEnemigoTerrestreAnimal>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}

// Crear enemigo aereo animal
AEnemigoAereo* AFabricaEnemigosAnimales::CrearAereo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoAereoAnimal* Enemigo = Mundo->SpawnActor<AEnemigoAereoAnimal>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}

// Crear enemigo acuatico animal
AEnemigoAcuatico* AFabricaEnemigosAnimales::CrearAcuatico(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoAcuaticoAnimal* Enemigo = Mundo->SpawnActor<AEnemigoAcuaticoAnimal>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}

// Crear enemigo subterraneo animal
AEnemigoSubterraneo* AFabricaEnemigosAnimales::CrearSubterraneo(FVector Posicion)
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AEnemigoSubterraneoAnimal* Enemigo = Mundo->SpawnActor<AEnemigoSubterraneoAnimal>(Posicion, FRotator::ZeroRotator);
        return Enemigo;
    }
    return nullptr;
}
