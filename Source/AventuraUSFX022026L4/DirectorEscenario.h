
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorEscenario.generated.h"

class AConstructorEscenario;

UCLASS()
class AVENTURAUSFX022026L4_API ADirectorEscenario : public AActor
{
    GENERATED_BODY()

public:
    ADirectorEscenario();

    // Recibe el Builder que construira el escenario
    void EstablecerConstructor(AConstructorEscenario* NuevoConstructor);

    // Organiza las etapas de construccion
    void ConstruirEscenario();

    // Devuelve los elementos construidos
    TArray<AActor*> ObtenerEscenario() const;

private:

    // Guarda la referencia al Builder seleccionado
    UPROPERTY()
        AConstructorEscenario* ConstructorActual;
};
