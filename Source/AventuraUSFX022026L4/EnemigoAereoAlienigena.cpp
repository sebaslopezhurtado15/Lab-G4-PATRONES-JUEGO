#include "EnemigoAereoAlienigena.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoAereoAlienigena::AEnemigoAereoAlienigena()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaDron = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaDron"));
    MallaDron->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Alien_Aereo_Dron.SM_Alien_Aereo_Dron"));

    if (MallaAsset.Succeeded())
    {
        MallaDron->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaDron->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaDron->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
