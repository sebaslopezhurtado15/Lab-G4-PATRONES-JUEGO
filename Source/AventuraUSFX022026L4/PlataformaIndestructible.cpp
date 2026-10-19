
#include "PlataformaIndestructible.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Materials/Material.h"

APlataformaIndestructible::APlataformaIndestructible()
{
    bDestructible = false;

    // Malla de la plataforma
    static ConstructorHelpers::FObjectFinder<UStaticMesh> PlataformaMeshAsset(
        TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'")
    );

    if (PlataformaMeshAsset.Succeeded())
    {
        Malla->SetStaticMesh(PlataformaMeshAsset.Object);
        Malla->SetRelativeScale3D(FVector(0.75f, 0.75f, 0.75f));
    }

    // Material azul
    static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAzul(
        TEXT("Material'/Game/MaterialesPaintball/M_PlataformaAzul.M_PlataformaAzul'")
    );

    if (MaterialAzul.Succeeded())
    {
        Malla->SetMaterial(0, MaterialAzul.Object);
    }

    // Colisiones
    Malla->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Malla->SetCollisionProfileName(TEXT("BlockAll"));
}
