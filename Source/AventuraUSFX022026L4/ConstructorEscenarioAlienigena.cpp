
#include "ConstructorEscenarioAlienigena.h"
#include "FabricaEnemigosAlienigenas.h"
#include "FabricaDestructible.h"
#include "FabricaIndestructible.h"
#include "FabricaPlataforma.h"
#include "Plataforma.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoSubterraneo.h"
#include "EnemigoAcuatico.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

// BUILDER ALIENIGENA - Construir enemigos
void AConstructorEscenarioAlienigena::ConstruirEnemigos()
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Crear la fabrica de enemigos alienigenas
        AFabricaEnemigosAlienigenas* Fabrica = Mundo->SpawnActor<AFabricaEnemigosAlienigenas>();
        APawn* Nave = UGameplayStatics::GetPlayerPawn(this, 0);

        if (Fabrica != nullptr && Nave != nullptr)
        {
            // Obtener posicion de la nave
            FVector Base = Nave->GetActorLocation();

            // Formacion de cuatro enemigos a la altura de la nave
            FVector Posiciones[4] = {
                Base + FVector(250.0f, 900.0f, 0.0f),   // Aereo - adelante derecha
                Base + FVector(250.0f, -1000.0f, 0.0f), // Terrestre - adelante izquierda
                Base + FVector(100.0f, -600.0f, 0.0f),  // Subterraneo - atras hacia el centro
                Base + FVector(100.0f, 600.0f, 0.0f)    // Acuatico - atras hacia el centro
            };

            // Crear enemigos mediante Abstract Factory
            AEnemigoAereo* Aereo = Fabrica->CrearAereo(Posiciones[0]);
            AEnemigoTerrestre* Terrestre = Fabrica->CrearTerrestre(Posiciones[1]);
            AEnemigoSubterraneo* Subterraneo = Fabrica->CrearSubterraneo(Posiciones[2]);
            AEnemigoAcuatico* Acuatico = Fabrica->CrearAcuatico(Posiciones[3]);

            // Orientar y guardar enemigo aereo
            if (Aereo != nullptr)
            {
                FVector Direccion = Base - Posiciones[0];
                Direccion.Z = 0.0f;
                Aereo->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Aereo);
            }

            // Orientar y guardar enemigo terrestre
            if (Terrestre != nullptr)
            {
                FVector Direccion = Base - Posiciones[1];
                Direccion.Z = 0.0f;
                Terrestre->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Terrestre);
            }

            // Orientar y guardar enemigo subterraneo
            if (Subterraneo != nullptr)
            {
                FVector Direccion = Base - Posiciones[2];
                Direccion.Z = 0.0f;
                Subterraneo->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Subterraneo);
            }

            // Orientar y guardar enemigo acuatico
            if (Acuatico != nullptr)
            {
                FVector Direccion = Base - Posiciones[3];
                Direccion.Z = 0.0f;
                Acuatico->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Acuatico);
            }
        }
    }
}

// BUILDER ALIENIGENA - Construir plataformas
void AConstructorEscenarioAlienigena::ConstruirPlataformas()
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        // Crear las fabricas de plataformas
        AFabricaPlataforma* FabricaD = Mundo->SpawnActor<AFabricaDestructible>();
        AFabricaPlataforma* FabricaI = Mundo->SpawnActor<AFabricaIndestructible>();
        APawn* Nave = UGameplayStatics::GetPlayerPawn(this, 0);

        if (FabricaD != nullptr && FabricaI != nullptr && Nave != nullptr)
        {
            // Crear ocho plataformas
            for (int i = 0; i < 8; i++)
            {
                // Garantizar al menos dos plataformas rojas
                int Tipo = (i == 0 || i == 4) ? 0 : FMath::RandRange(0, 1);
                AFabricaPlataforma* FabricaActual = nullptr;

                if (Tipo == 0)
                {
                    FabricaActual = FabricaD;
                }
                else
                {
                    FabricaActual = FabricaI;
                }

                // Posicion de la plataforma respecto a la nave
                FVector Posicion = Nave->GetActorLocation() + FVector(250.0f + (i % 4) * 200.0f, -550.0f + (i / 4) * 1100.0f, 0.0f);

                // Crear plataforma mediante Factory Method
                APlataforma* Plataforma = FabricaActual->CrearPlataforma(Posicion);

                if (Plataforma != nullptr)
                {
                    ElementosConstruidos.Add(Plataforma);
                }
            }
        }
    }
}
