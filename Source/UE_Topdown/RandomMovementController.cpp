// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMovementController.h"

URandomMovementController::URandomMovementController()
{
}

URandomMovementController::~URandomMovementController()
{
}

FVector URandomMovementController::Move(const FVector& currentPos)
{
	// 랜덤한 step 벡터를 받아서 현재 위치에 값을 더함 
	FVector step = GenerateRandomStep(0, 1);
	return currentPos + step;
}

FVector URandomMovementController::RandomJump(const FVector& currentPos)
{
	FVector step = GenerateRandomStep(1, 10);

	return currentPos + step;
}

FVector URandomMovementController::GenerateRandomStep(int32 Min, int32 Max)
{
	FVector Step;
	do
	{
		int32 RandXStep = FMath::RandRange(Min, Max);
		int32 RandYStep = FMath::RandRange(Min, Max);
		Step = FVector(RandXStep, RandYStep, 0.f);
	} while (Step.X == 0 && Step.Y == 0); // 조금이라도 이동을 해야함

	return Step;
}