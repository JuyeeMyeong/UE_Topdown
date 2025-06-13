// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMoveRandomActor.generated.h"

class URandomMovementController;
class UEventGenerator;

UCLASS()
class UE_TOPDOWN_API AMoveRandomActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveRandomActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY()
	URandomMovementController* RMovementController;
	UPROPERTY()
	UEventGenerator* EventGenerator; 
	UPROPERTY(EditAnywhere, Category = "Movement")
	int32 TotalSteps = 10; // �⺻�� 10ȸ, ���߿� ���� �����ϵ��� ���� 
	UPROPERTY()
	int32 CurrentStep = 0;
	UPROPERTY()
	float ElapsedTime = 0.0f;


	FVector CurrentPosition;
	float TotalDistance;
	int32 EventCount; // 50% Ȯ���� trigger�� �̺�Ʈ Ƚ�� 
	bool bHasPrintedSummary;

	void Step();
	void PrintSummary();
};
