
#include "EnemigoTerrestreAnimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoTerrestreAnimal::AEnemigoTerrestreAnimal()
{
    
    MallaZorro = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaZorro"));
    MallaZorro->SetupAttachment(GetCapsuleComponent());

    // Cargar la malla importada en Unreal
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Game/Enemigos/Mallas/SM_Animal_Terrestre_Zorro.SM_Animal_Terrestre_Zorro"));

    if (MallaAsset.Succeeded())
    {
        MallaZorro->SetStaticMesh(MallaAsset.Object);
    }

    // Ajustar la posicion de la malla respecto a la capsula
    MallaZorro->SetRelativeLocation(FVector(0.0f, 0.0f, -25.0f));

    // La capsula se encarga de las colisiones
    MallaZorro->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
