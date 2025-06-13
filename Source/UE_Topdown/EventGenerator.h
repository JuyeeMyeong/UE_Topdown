// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EventGenerator.generated.h"
/**
 * 
 */
UCLASS()
class UE_TOPDOWN_API UEventGenerator : public UObject
{
	GENERATED_BODY()
public:
	UEventGenerator();
	virtual ~UEventGenerator();

	virtual bool ShouldTriggerEvent() const;
};
