// Fill out your copyright notice in the Description page of Project Settings.

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
	// Sets default values for this actor's properties
	AControladorJuegoFacade();

	void IniciarJuego();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ComprobarVictoria();
	FTimerHandle TemporizadorVictoria;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
