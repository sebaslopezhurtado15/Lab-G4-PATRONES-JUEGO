// Copyright Epic Games, Inc. All Rights Reserve

#include "AventuraUSFX022026L4Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "PlataformaDestructible.h"
#include "Engine/StaticMesh.h"
#include "Enemigo.h"

AAventuraUSFX022026L4Projectile::AAventuraUSFX022026L4Projectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AAventuraUSFX022026L4Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}


void AAventuraUSFX022026L4Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Mostrar el objeto con el que chocamos
	UE_LOG(LogTemp, Warning, TEXT("Impacto con: %s"), *GetNameSafe(OtherActor));

	// Comprobar si el objeto es una plataformaDestructible
	APlataformaDestructible* Plataforma = Cast<APlataformaDestructible>(OtherActor);

	if (Plataforma != nullptr)
	{
		Plataforma->RecibirDanio(50.0f);
	}

	// Comprobar si la bala impacto contra un enemigo
	AEnemigo* Enemigo = Cast<AEnemigo>(OtherActor);

	if (Enemigo != nullptr)
	{
		Enemigo->RecibirDanio(50.0f);
	}


	// Aplicar impulso si el objeto tiene fisica
	if ((OtherActor != nullptr) && (OtherActor != this) &&
		(OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	// Destruir proyectil despues del impacto
	Destroy();
}
