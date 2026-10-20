
#include "FabricaIndestructible.h"
#include "PlataformaIndestructible.h"
#include "Engine/World.h"

APlataforma* AFabricaIndestructible::CrearPlataforma(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<APlataformaIndestructible>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}
