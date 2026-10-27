
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

    FVector movimientoLimitesMaximos;
    FVector movimientoLimitesMinimos;
    FVector movimientoVelocidades;
    FVector movimientoDireccion;
    FVector movimientoEjes;


};