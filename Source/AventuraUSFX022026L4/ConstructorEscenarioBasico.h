
#pragma once

#include "CoreMinimal.h"
#include "ConstructorEscenario.h"
#include "ConstructorEscenarioBasico.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AConstructorEscenarioBasico : public AConstructorEscenario
{
    GENERATED_BODY()

public:

    // Construye los cuatro enemigos animales
    virtual void ConstruirEnemigos() override;

    // Construye las plataformas del escenario basico
    virtual void ConstruirPlataformas() override;
};
