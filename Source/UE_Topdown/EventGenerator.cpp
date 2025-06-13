// Fill out your copyright notice in the Description page of Project Settings.


#include "EventGenerator.h"
#include "Math/UnrealMathUtility.h"

UEventGenerator::UEventGenerator()
{
}

UEventGenerator::~UEventGenerator()
{
}

//50%의 확률로 이벤트를 발생시킬지 결정 0.5 이상일 때 true -> (trigger event) 
bool UEventGenerator::ShouldTriggerEvent() const
{
	return FMath::RandRange(0.0f, 1.0f) >= 0.5f;
}