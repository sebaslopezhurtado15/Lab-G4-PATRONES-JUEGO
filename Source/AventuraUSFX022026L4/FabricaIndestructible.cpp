
#include "FabricaIndestructible.h"
#include "PlataformaIndestructible.h"
#include "Engine/World.h"

APlataforma* AFabricaIndestructible::CrearPlataforma(FVector Posicion)
{
    if (!GetWorld()) return nullptr;
    return GetWorld()->SpawnActor<APlataformaIndestructible>(Posicion, FRotator::ZeroRotator);
}
