
#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaDestructible.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API APlataformaDestructible : public APlataforma
{
    GENERATED_BODY()

public:
    APlataformaDestructible();
    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;

private:
    FVector PosicionInicial;
    float Velocidad = 120.0f;
    float Direccion = 1.0f;
    float Limite = 200.0f;

};