#include "EnemigoAereoAnimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoAereoAnimal::AEnemigoAereoAnimal()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaAve = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaAve"));
    MallaAve->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Animal_Aereo_Ave.SM_Animal_Aereo_Ave"));

    if (MallaAsset.Succeeded())
    {
        MallaAve->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaAve->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaAve->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
