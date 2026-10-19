
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo.generated.h"

UCLASS()
class AVENTURAUSFX022026L4_API AEnemigo : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemigo();
    //Dos responsabilidades(Vida y RecibirDanio)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
        float Vida;

    void RecibirDanio(float Danio);
};
