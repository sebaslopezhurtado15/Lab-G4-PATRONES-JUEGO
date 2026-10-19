
#pragma once

#include "CoreMinimal.h"
#include "ConstructorEscenario.h"
#include "ConstructorEscenarioBasico.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AConstructorEscenarioBasico : public AConstructorEscenario
{
    GENERATED_BODY()

public:
    virtual void ConstruirEnemigos() override;
    virtual void ConstruirPlataformas() override;
};
