#include "EnemigoAcuaticoAnimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoAcuaticoAnimal::AEnemigoAcuaticoAnimal()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaPez = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPez"));
    MallaPez->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Animal_Acuatico_Pez.SM_Animal_Acuatico_Pez"));

    if (MallaAsset.Succeeded())
    {
        MallaPez->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaPez->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaPez->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
