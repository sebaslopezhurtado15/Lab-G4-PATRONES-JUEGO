
#include "FabricaDestructible.h"
#include "PlataformaDestructible.h"
#include "Engine/World.h"

APlataforma* AFabricaDestructible::CrearPlataforma(FVector Posicion)
{
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        return Mundo->SpawnActor<APlataformaDestructible>(Posicion, FRotator::ZeroRotator);
    }
    return nullptr;
}
