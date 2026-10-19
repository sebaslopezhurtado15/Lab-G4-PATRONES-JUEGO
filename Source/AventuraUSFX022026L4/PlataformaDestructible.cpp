
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
}

void APlataformaDestructible::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Movimiento de ida y vuelta sobre el eje Y
    FVector Posicion = GetActorLocation();
    Posicion.Y += Velocidad * Direccion * DeltaTime;

    if (FMath::Abs(Posicion.Y - PosicionInicial.Y) >= Limite)
        Direccion *= -1.0f;

    SetActorLocation(Posicion, true);
}
