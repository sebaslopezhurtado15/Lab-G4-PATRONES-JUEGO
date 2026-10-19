
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorEscenario.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AConstructorEscenario : public AActor
{
    GENERATED_BODY()

public:
    AConstructorEscenario();

    // Etapas de construccion del escenario
    virtual void ConstruirEnemigos()
        PURE_VIRTUAL(AConstructorEscenario::ConstruirEnemigos, );

    virtual void ConstruirPlataformas()
        PURE_VIRTUAL(AConstructorEscenario::ConstruirPlataformas, );

    // Devuelve los elementos construidos del escenario
    const TArray<AActor*>& ObtenerResultado() const
    {
        return ElementosConstruidos;
    }

protected:
    UPROPERTY()
        TArray<AActor*> ElementosConstruidos;

};
