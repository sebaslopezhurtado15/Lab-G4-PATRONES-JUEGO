
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

class UStaticMeshComponent;

UCLASS()
class AVENTURAUSFX022026L4_API APlataforma : public AActor
{
    GENERATED_BODY()

public:
    APlataforma();

    // Caracteristicas comunes de todas las plataformas
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataforma")
        UStaticMeshComponent* Malla;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma")
        float Vida;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma")
        bool bDestructible;

    void RecibirDanio(float Danio);
};
