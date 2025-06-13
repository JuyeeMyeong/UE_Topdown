// Fill out your copyright notice in the Description page of Project Settings.


#include "EventGenerator.h"
#include "Math/UnrealMathUtility.h"

UEventGenerator::UEventGenerator()
{
}

UEventGenerator::~UEventGenerator()
{
}

//50%�� Ȯ���� �̺�Ʈ�� �߻���ų�� ���� 0.5 �̻��� �� true -> (trigger event) 
bool UEventGenerator::ShouldTriggerEvent() const
{
	return FMath::RandRange(0.0f, 1.0f) >= 0.5f;
}