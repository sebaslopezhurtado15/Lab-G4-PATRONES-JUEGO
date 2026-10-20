#include "EnemigoTerrestreAlienigena.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoTerrestreAlienigena::AEnemigoTerrestreAlienigena()
{
    // Crear la malla visual y unirla a la capsula del enemigo.
    MallaGuardian = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaGuardian"));
    MallaGuardian->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla que ya importamos en Unreal Engine.
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Alien_Terrestre_Guardian.SM_Alien_Terrestre_Guardian"));

    if (MallaAsset.Succeeded())
    {
        MallaGuardian->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la malla respecto a la capsula, igual que el zorro.
    MallaGuardian->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula mantiene las colisiones; la malla es solamente visual.
    MallaGuardian->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
