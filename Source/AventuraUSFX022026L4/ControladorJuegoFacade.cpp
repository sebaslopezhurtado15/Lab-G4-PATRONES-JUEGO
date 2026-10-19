
#include "ControladorJuegoFacade.h"
#include "ConstructorEscenarioBasico.h"
#include "PlataformaDestructible.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

AControladorJuegoFacade::AControladorJuegoFacade()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AControladorJuegoFacade::BeginPlay()
{
    Super::BeginPlay();
}

void AControladorJuegoFacade::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// FACADE - Iniciar el juego
void AControladorJuegoFacade::IniciarJuego()
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Crear el Builder
        AConstructorEscenarioBasico* Constructor = Mundo->SpawnActor<AConstructorEscenarioBasico>();

        if (Constructor != nullptr)
        {
            // Construir el escenario
            Constructor->ConstruirEnemigos();
            Constructor->ConstruirPlataformas();

            // Buscar plataformas destructibles
            TArray<AActor*> PlataformasRojas;

            UGameplayStatics::GetAllActorsOfClass(this,APlataformaDestructible::StaticClass(),PlataformasRojas);

            // Iniciar la comprobacion de victoria
            if (PlataformasRojas.Num() > 0)
            {
                Mundo->GetTimerManager().SetTimer(TemporizadorVictoria,this,&AControladorJuegoFacade::ComprobarVictoria,1.0f,true);
            }
        }
    }
}

// FACADE - Comprobar la victoria
void AControladorJuegoFacade::ComprobarVictoria()
{
    TArray<AActor*> PlataformasRojas;

    // Buscar plataformas destructibles
    UGameplayStatics::GetAllActorsOfClass(this,APlataformaDestructible::StaticClass(),PlataformasRojas);

    // Victoria cuando no quedan plataformas rojas
    if (PlataformasRojas.Num() == 0)
    {
        GetWorldTimerManager().ClearTimer(TemporizadorVictoria);

        if (GEngine != nullptr)
        {
            GEngine->AddOnScreenDebugMessage(-1,15.0f,FColor::Green,TEXT("VICTORIA - Todas las plataformas rojas eliminadas"));
        }
    }
}
