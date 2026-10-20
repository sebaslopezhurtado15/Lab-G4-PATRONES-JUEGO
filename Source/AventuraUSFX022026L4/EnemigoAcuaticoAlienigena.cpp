#include "EnemigoAcuaticoAlienigena.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoAcuaticoAlienigena::AEnemigoAcuaticoAlienigena()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaMedusa = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMedusa"));
    MallaMedusa->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Alien_Acuatico_Medusa.SM_Alien_Acuatico_Medusa"));

    if (MallaAsset.Succeeded())
    {
        MallaMedusa->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaMedusa->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaMedusa->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
