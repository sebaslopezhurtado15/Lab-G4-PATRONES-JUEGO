
#include "ConstructorEscenarioBasico.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoSubterraneo.h"
#include "EnemigoAcuatico.h"
#include "Plataforma.h"
#include "FabricaEnemigosAnimales.h"
#include "FabricaPlataforma.h"
#include "FabricaDestructible.h"
#include "FabricaIndestructible.h"
#include "Engine/World.h"

//Construir los cuatro enemigos animales
void AConstructorEscenarioBasico::ConstruirEnemigos()
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        AFabricaEnemigosAnimales* Fabrica = Mundo->SpawnActor<AFabricaEnemigosAnimales>();
        APawn* Nave = UGameplayStatics::GetPlayerPawn(this, 0);

        if (Fabrica != nullptr && Nave != nullptr)
        {
            FVector Base = Nave->GetActorLocation();

            // Formacion de dos filas y dos columnas
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

            // Orientar los enemigos hacia la nave y guardar sus referencias
            if (Aereo != nullptr)
            {
                FVector Direccion = Base - Posiciones[0];
                Direccion.Z = 0.0f;
                Aereo->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Aereo);
            }

            if (Terrestre != nullptr)
            {
                FVector Direccion = Base - Posiciones[1];
                Direccion.Z = 0.0f;
                Terrestre->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Terrestre);
            }

            if (Subterraneo != nullptr)
            {
                FVector Direccion = Base - Posiciones[2];
                Direccion.Z = 0.0f;
                Subterraneo->SetActorRotation(Direccion.Rotation());
                ElementosConstruidos.Add(Subterraneo);
            }

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

//Construir las ocho plataformas
void AConstructorEscenarioBasico::ConstruirPlataformas()
{
    UWorld* Mundo = GetWorld();

    if (Mundo != nullptr)
    {
        //Creamos las 2 fabricas
        AFabricaPlataforma* FabricaD = Mundo->SpawnActor<AFabricaDestructible>();
        AFabricaPlataforma* FabricaI = Mundo->SpawnActor<AFabricaIndestructible>();

        if (FabricaD != nullptr && FabricaI != nullptr)
        {
            APawn* Nave = UGameplayStatics::GetPlayerPawn(this, 0);

            if (Nave != nullptr)
            {
                // Crear ocho plataformas garantizando al menos una roja
                for (int i = 0; i < 8; i++)
                {
                    int Tipo = (i == 2) ? 0 : FMath::RandRange(0, 1);
                    AFabricaPlataforma* FabricaActual = nullptr;

                    if (Tipo == 0)
                    {
                        FabricaActual = FabricaD;
                    }
                    else
                    {
                        FabricaActual = FabricaI;
                    }

                    // Calcular la posicion respecto a la nave
                    FVector Posicion = Nave->GetActorLocation() + FVector(350.0f + (i / 4) * 250.0f, -600.0f + (i % 4) * 300.0f, 0.0f);

                    // Crear y guardar la plataforma
                    APlataforma* Plataforma = FabricaActual->CrearPlataforma(Posicion);

                    if (Plataforma != nullptr)
                    {
                        ElementosConstruidos.Add(Plataforma);
                    }
                }
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("No se encontro la nave"));
            }
        }
    }
}






/*De 5 a 20 de forma aleatria
    UWorld* Mundo = GetWorld();
    if (Mundo != nullptr)
    {
        AFabricaEnemigosAnimales* Fabrica = Mundo->SpawnActor<AFabricaEnemigosAnimales>();
        APawn* Nave = UGameplayStatics::GetPlayerPawn(this, 0);

        if (Fabrica != nullptr && Nave != nullptr)
        {
            FVector Base = Nave->GetActorLocation();
            int Cantidad = FMath::RandRange(5, 20);

            for (int i = 0; i < Cantidad; i++)
            {
                int Tipo = FMath::RandRange(0, 3);
                FVector Posicion = Base + FVector(100.0f + (i / 4) * 150.0f, -900.0f + (i % 4) * 600.0f, 0.0f);

                AEnemigo* Enemigo = nullptr;

                switch (Tipo)
                {
                case 0: Enemigo = Fabrica->CrearAereo(Posicion); break;
                case 1: Enemigo = Fabrica->CrearTerrestre(Posicion); break;
                case 2: Enemigo = Fabrica->CrearSubterraneo(Posicion); break;
                case 3: Enemigo = Fabrica->CrearAcuatico(Posicion); break;
                }

                if (Enemigo != nullptr)
                {
                    FVector Direccion = Base - Posicion;
                    Direccion.Z = 0.0f;
                    Enemigo->SetActorRotation(Direccion.Rotation());
                    ElementosConstruidos.Add(Enemigo);
                }
            }
        }
    }*/