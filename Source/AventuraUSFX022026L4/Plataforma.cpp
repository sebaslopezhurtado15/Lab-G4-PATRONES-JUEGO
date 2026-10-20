
#include "Plataforma.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"


APlataforma::APlataforma()
{
	PrimaryActorTick.bCanEverTick = true;

	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	RootComponent = Malla;

	// Asignar una malla visible tipo cubo
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaCubo(
		TEXT("/Engine/BasicShapes/Cube.Cube"));

	if (MallaCubo.Succeeded())
	{
		Malla->SetStaticMesh(MallaCubo.Object);
		Malla->SetRelativeScale3D(FVector(1.5f, 2.5f, 0.35f));
	}

	// Colisiones
	Malla->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Malla->SetCollisionProfileName(TEXT("BlockAll"));

	// Valores base
	Vida = 100.0f;
	bDestructible = true;
}

void APlataforma::RecibirDanio(float Danio)
{
    if (bDestructible == true && Danio > 0.0f)
    {
        Vida -= Danio;

        if (Vida <= 0.0f)
        {
            Destroy();
        }
    }
}
