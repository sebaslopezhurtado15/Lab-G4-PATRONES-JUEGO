
#include "AventuraUSFX022026L4GameMode.h"
#include "AventuraUSFX022026L4Pawn.h"
#include "Engine/World.h"

// Builder
#include "ConstructorEscenario.h"
#include "ConstructorEscenarioBasico.h"

AAventuraUSFX022026L4GameMode::AAventuraUSFX022026L4GameMode()
{
    DefaultPawnClass = AAventuraUSFX022026L4Pawn::StaticClass();
}

void AAventuraUSFX022026L4GameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* Mundo = GetWorld();
    if (!Mundo) return;

    // BUILDER - Construye el escenario por etapas
    AConstructorEscenario* Constructor = Mundo->SpawnActor<AConstructorEscenarioBasico>();
    if (!Constructor) return;

    Constructor->ConstruirEnemigos();
    Constructor->ConstruirPlataformas();
}
