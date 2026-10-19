
#include "FabricaDestructible.h"
#include "PlataformaDestructible.h"
#include "Engine/World.h"

APlataforma* AFabricaDestructible::CrearPlataforma(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<APlataformaDestructible>(Posicion, FRotator::ZeroRotator);
}
