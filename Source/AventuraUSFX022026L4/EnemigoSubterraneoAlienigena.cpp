#include "EnemigoSubterraneoAlienigena.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoSubterraneoAlienigena::AEnemigoSubterraneoAlienigena()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaTaladro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaTaladro"));
    MallaTaladro->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Alien_Subterraneo_Taladro.SM_Alien_Subterraneo_Taladro"));

    if (MallaAsset.Succeeded())
    {
        MallaTaladro->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaTaladro->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaTaladro->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
