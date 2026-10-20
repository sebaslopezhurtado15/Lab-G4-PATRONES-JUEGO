
#include "FabricaDestructible.h"
#include "PlataformaDestructible.h"
#include "Engine/World.h"


APlataforma* AFabricaDestructible::CrearPlataforma(FVector Posicion)
{
    // Obtenemos el mundo de Unreal
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Creamos una plataforma indestructible
        APlataformaDestructible* Plataforma = Mundo->SpawnActor<APlataformaDestructible>(Posicion, FRotator::ZeroRotator);
        return Plataforma;
    }
    return nullptr;
}