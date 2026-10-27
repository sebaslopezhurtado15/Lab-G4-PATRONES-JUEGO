
#include "AventuraUSFX022026L4GameMode.h"
#include "AventuraUSFX022026L4Pawn.h"
#include "Engine/World.h"

//Facade
#include "ControladorJuegoFacade.h"


AAventuraUSFX022026L4GameMode::AAventuraUSFX022026L4GameMode()
{
    DefaultPawnClass = AAventuraUSFX022026L4Pawn::StaticClass();
}

void AAventuraUSFX022026L4GameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Facade inicia el escenario mediante Builder.
        AControladorJuegoFacade* Fachada = Mundo->SpawnActor<AControladorJuegoFacade>();

        if (Fachada != nullptr)
        {
            Fachada->IniciarJuego();
        }
    }
}
