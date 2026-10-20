#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "ControladorJuegoFacade.generated.h"


UCLASS()
class AVENTURAUSFX022026L4_API AControladorJuegoFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	AControladorJuegoFacade();

	void IniciarJuego();


protected:
    void ComprobarVictoria();
    FTimerHandle TemporizadorVictoria;

};
