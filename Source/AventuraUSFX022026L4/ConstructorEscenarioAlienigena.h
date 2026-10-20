
#pragma once

#include "CoreMinimal.h"
#include "ConstructorEscenario.h"
#include "ConstructorEscenarioAlienigena.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AConstructorEscenarioAlienigena : public AConstructorEscenario
{
    GENERATED_BODY()

public:

    //Construye los cuatro enemigos alienigenas
    virtual void ConstruirEnemigos() override;

    //Construye las plataformas del escenario alienigena
    virtual void ConstruirPlataformas() override;
};
