
#include "DirectorEscenario.h"
#include "ConstructorEscenario.h"

// Constructor del Director
ADirectorEscenario::ADirectorEscenario()
{
    PrimaryActorTick.bCanEverTick = false;
    ConstructorActual = nullptr;
}

// Recibe el Builder que utilizaremos
void ADirectorEscenario::EstablecerConstructor(AConstructorEscenario* NuevoConstructor)
{
    ConstructorActual = NuevoConstructor;
}

// Organiza la construccion del escenario
void ADirectorEscenario::ConstruirEscenario()
{
    if (ConstructorActual != nullptr)
    {
        // Primera etapa: construir enemigos
        ConstructorActual->ConstruirEnemigos();

        // Segunda etapa: construir plataformas
        ConstructorActual->ConstruirPlataformas();
    }
}

// Devuelve el escenario construido
TArray<AActor*> ADirectorEscenario::ObtenerEscenario() const
{
    TArray<AActor*> Elementos;

    if (ConstructorActual != nullptr)
    {
        Elementos = ConstructorActual->ObtenerResultado();
    }

    return Elementos;
}
