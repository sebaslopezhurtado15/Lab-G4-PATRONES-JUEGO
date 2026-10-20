
#include "ControladorJuegoFacade.h"
#include "DirectorEscenario.h"
#include "ConstructorEscenario.h"
#include "ConstructorEscenarioBasico.h"
#include "ConstructorEscenarioAlienigena.h"
#include "PlataformaDestructible.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

AControladorJuegoFacade::AControladorJuegoFacade()
{
    PrimaryActorTick.bCanEverTick = false;
}

// FACADE - Iniciar el juego
void AControladorJuegoFacade::IniciarJuego()
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Crear el Director del Builder
        ADirectorEscenario* Director = Mundo->SpawnActor<ADirectorEscenario>();

        // Puntero al Builder abstracto
        AConstructorEscenario* Constructor = nullptr;

        // Seleccionar escenario: 0 = Basico, 1 = Alienigena
        int TipoEscenario = 0;

        if (TipoEscenario == 0)
        {
            // Crear el Builder del escenario basico
            Constructor = Mundo->SpawnActor<AConstructorEscenarioBasico>();
            UE_LOG(LogTemp, Warning, TEXT("ESCENARIO BASICO - ANIMALES"));
        }
        else if (TipoEscenario == 1)
        {
            // Crear el Builder del escenario alienigena
            Constructor = Mundo->SpawnActor<AConstructorEscenarioAlienigena>();
            UE_LOG(LogTemp, Warning, TEXT("ESCENARIO ALIENIGENA"));
        }

        if (Director != nullptr && Constructor != nullptr)
        {
            // Asignar el Builder seleccionado al Director
            Director->EstablecerConstructor(Constructor);

            // El Director organiza la construccion
            Director->ConstruirEscenario();

            // Obtener el resultado del Builder
            UE_LOG(LogTemp, Log, TEXT("Builder creo %d elementos"), Director->ObtenerEscenario().Num());

            // Buscar plataformas rojas
            TArray<AActor*> PlataformasRojas;
            UGameplayStatics::GetAllActorsOfClass(this, APlataformaDestructible::StaticClass(), PlataformasRojas);

            // Activar la comprobacion de victoria
            if (PlataformasRojas.Num() > 0)
            {
                Mundo->GetTimerManager().SetTimer(TemporizadorVictoria, this, &AControladorJuegoFacade::ComprobarVictoria, 1.0f, true);
            }
        }
    }
}

// FACADE - Comprobar la victoria
void AControladorJuegoFacade::ComprobarVictoria()
{
    TArray<AActor*> PlataformasRojas;

    // Buscar plataformas destructibles
    UGameplayStatics::GetAllActorsOfClass(this, APlataformaDestructible::StaticClass(), PlataformasRojas);

    // Victoria cuando no quedan plataformas rojas
    if (PlataformasRojas.Num() == 0)
    {
        GetWorldTimerManager().ClearTimer(TemporizadorVictoria);

        if (GEngine != nullptr)
        {
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("VICTORIA - Todas las plataformas rojas eliminadas"));
        }
    }
}
