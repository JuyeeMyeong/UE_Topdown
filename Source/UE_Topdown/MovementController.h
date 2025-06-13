// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MovementController.generated.h"

UCLASS()
class UE_TOPDOWN_API UMovementController : public UObject
{
    GENERATED_BODY()

public:
    UMovementController();
    virtual ~UMovementController();

    virtual FVector Move(const FVector& currentPos) PURE_VIRTUAL(UMovementController::Move, return FVector::ZeroVector;);
    virtual FVector RandomJump(const FVector& currentPos) PURE_VIRTUAL(UMovementController::RandomJump, return FVector::ZeroVector;);

};

