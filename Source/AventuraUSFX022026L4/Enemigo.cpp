
#include "Enemigo.h"

AEnemigo::AEnemigo()
{
    // Desactiva Tick
    PrimaryActorTick.bCanEverTick = false;
    Vida = 100.0f;
}

void AEnemigo::RecibirDanio(float Danio)
{
    Vida -= Danio;

    if (Vida <= 0.0f)
    {
        Destroy();
    }
}
