// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovementController.h"
#include "RandomMovementController.generated.h"


UCLASS()
class UE_TOPDOWN_API URandomMovementController : public UMovementController
{
    GENERATED_BODY()

public:
    URandomMovementController();
    virtual ~URandomMovementController();

    virtual FVector Move(const FVector& currentPos) override;
    virtual FVector RandomJump(const FVector& currentPos) override;

private:
    FVector GenerateRandomStep(int32 Min, int32 Max);
};