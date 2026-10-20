
#include "FabricaIndestructible.h"
#include "PlataformaIndestructible.h"
#include "Engine/World.h"


APlataforma* AFabricaIndestructible::CrearPlataforma(FVector Posicion)
{
    // Obtenemos el mundo de Unreal
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Creamos una plataforma indestructible
        APlataformaIndestructible* Plataforma = Mundo->SpawnActor<APlataformaIndestructible>(Posicion, FRotator::ZeroRotator);
        return Plataforma;
    }
    return nullptr;
}
