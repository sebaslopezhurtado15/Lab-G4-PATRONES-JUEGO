#include "EnemigoSubterraneoAnimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoSubterraneoAnimal::AEnemigoSubterraneoAnimal()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaTopo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaTopo"));
    MallaTopo->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Animal_Subterraneo_Topo.SM_Animal_Subterraneo_Topo"));

    if (MallaAsset.Succeeded())
    {
        MallaTopo->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaTopo->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaTopo->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
