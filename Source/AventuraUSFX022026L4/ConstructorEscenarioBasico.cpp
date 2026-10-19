
#include "ConstructorEscenarioBasico.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "FabricaEnemigos.h"
#include "FabricaEnemigosAnimales.h"
#include "FabricaEnemigosAlienigenas.h"
#include "FabricaPlataforma.h"
#include "FabricaDestructible.h"
#include "FabricaIndestructible.h"
#include "Engine/World.h"

void AConstructorEscenarioBasico::ConstruirEnemigos()
{
    UWorld* Mundo = GetWorld();
    if (!Mundo) return;

    int TipoFamilia = FMath::RandRange(0, 1);
    AFabricaEnemigos* Fabrica = nullptr;
    if (TipoFamilia == 0)
    {
        Fabrica = Mundo->SpawnActor<AFabricaEnemigosAnimales>();
    }
    else
    {
        Fabrica = Mundo->SpawnActor<AFabricaEnemigosAlienigenas>();
    }
    if (!Fabrica) return;

    // Construccion de los cuatro tipos de enemigos
    Fabrica->CrearAereo(FVector(200.0f, -850.0f, 200.0f));
    Fabrica->CrearTerrestre(FVector(650.0f, -850.0f, 160.0f));
    Fabrica->CrearSubterraneo(FVector(200.0f, 850.0f, 160.0f));
    Fabrica->CrearAcuatico(FVector(650.0f, 850.0f, 160.0f));
}


void AConstructorEscenarioBasico::ConstruirPlataformas()
{
    UWorld* Mundo = GetWorld();
    if (!Mundo) return;

    AFabricaPlataforma* FabricaD = Mundo->SpawnActor<AFabricaDestructible>();
    AFabricaPlataforma* FabricaI = Mundo->SpawnActor<AFabricaIndestructible>();

    if (!FabricaD || !FabricaI) return;

    // Obtener la posicion real de la nave
    APawn* Nave = UGameplayStatics::GetPlayerPawn(this, 0);

    if (!Nave)
    {
        UE_LOG(LogTemp, Error, TEXT("No se encontro la nave"));
        return;
    }

    // Crear ocho plataformas cerca de la nave
    for (int i = 0; i < 8; i++)
    {
        // Garantizar una destructible para comprobar el daño
        int Tipo = (i == 2) ? 0 : FMath::RandRange(0, 1);

        AFabricaPlataforma* FabricaActual = (Tipo == 0) ? FabricaD : FabricaI;

        FVector Posicion = Nave->GetActorLocation() +FVector(350.0f + (i / 4) * 250.0f,-600.0f + (i % 4) * 300.0f,0.0f);
        FabricaActual->CrearPlataforma(Posicion);
    }
}

