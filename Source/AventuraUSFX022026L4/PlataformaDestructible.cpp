
#include "PlataformaDestructible.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"

APlataformaDestructible::APlataformaDestructible()
{
    // Habilita el movimiento
    PrimaryActorTick.bCanEverTick = true;
    bDestructible = true;

    // Malla de la plataforma
    static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(
        TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")
    );

    if (PlataformaMeshAsset.Succeeded())
    {
        Malla->SetStaticMesh(PlataformaMeshAsset.Object);
        Malla->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.75f));
    }

    // Material rojo
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialRojo(
        TEXT("Material'/Game/MaterialesPaintball/M_PlataformaRoja.M_PlataformaRoja'")
    );

    if (MaterialRojo.Succeeded())
    {
        Malla->SetMaterial(0, MaterialRojo.Object);
    }
}


void APlataformaDestructible::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation();

    // Limites maximos aleatorios
    movimientoLimitesMaximos = FVector(
        FMath::RandRange(200.0f, 400.0f),
        FMath::RandRange(200.0f, 400.0f),
        FMath::RandRange(200.0f, 400.0f)
    );

    // Limites minimos aleatorios
    movimientoLimitesMinimos = FVector(
        FMath::RandRange(-400.0f, -200.0f),
        FMath::RandRange(-400.0f, -200.0f),
        FMath::RandRange(-400.0f, -200.0f)
    );

    // Velocidades aleatorias
    movimientoVelocidades = FVector(
        FMath::RandRange(50.0f, 200.0f),
        FMath::RandRange(50.0f, 200.0f),
        FMath::RandRange(50.0f, 200.0f)
    );

    // Direccion inicial aleatoria
    movimientoDireccion = FVector(
        FMath::RandRange(0, 1) == 0 ? -1.0f : 1.0f,
        FMath::RandRange(0, 1) == 0 ? -1.0f : 1.0f,
        FMath::RandRange(0, 1) == 0 ? -1.0f : 1.0f
    );

    // Movimiento solo en el eje Y
    movimientoEjes = FVector(0.0f, 1.0f, 0.0f);
}

void APlataformaDestructible::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Posicion = GetActorLocation();

    // Movimiento utilizando FVector
    Posicion += movimientoVelocidades *
        movimientoDireccion *
        movimientoEjes * DeltaTime;

    // Distancia desde la posicion inicial
    float DistanciaY = Posicion.Y - PosicionInicial.Y;

    // Limite maximo
    if (DistanciaY >= movimientoLimitesMaximos.Y)
    {
        Posicion.Y = PosicionInicial.Y + movimientoLimitesMaximos.Y;
        movimientoDireccion.Y = -1.0f;
    }

    // Limite minimo
    else if (DistanciaY <= movimientoLimitesMinimos.Y)
    {
        Posicion.Y = PosicionInicial.Y + movimientoLimitesMinimos.Y;
        movimientoDireccion.Y = 1.0f;
    }

    // Detectar si la plataforma choco
    FHitResult Choque;

    SetActorLocation(Posicion, true, &Choque);

    // Si encontro un obstaculo, invertir direccion
    if (Choque.bBlockingHit)
    {
        movimientoDireccion.Y *= -1.0f;
    }

}

