
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AventuraUSFX022026L4GameMode.generated.h"

UCLASS(MinimalAPI)
class AAventuraUSFX022026L4GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AAventuraUSFX022026L4GameMode();

protected:
    virtual void BeginPlay() override;
};
