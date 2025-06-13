// Fill out your copyright notice in the Description page of Project Settings.


#include "AMoveRandomActor.h"
#include "RandomMovementController.h"
#include "EventGenerator.h"
#include "Math/Vector2D.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMoveRandomActor::AMoveRandomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bHasPrintedSummary = false;

}

// Called when the game starts or when spawned
void AMoveRandomActor::BeginPlay()
{
	Super::BeginPlay();

	// Random Movement ��Ʈ�ѷ��� Event Generator ��ü ����
	RMovementController = NewObject<URandomMovementController>();
	EventGenerator = NewObject<UEventGenerator>();

	// ó�� 0,0 ���� ���� 
	CurrentPosition = FVector(0, 0, GetActorLocation().Z);
	TotalDistance = 0.f;
	EventCount = 0;

	SetActorLocation(CurrentPosition);

	UE_LOG(LogTemp, Log, TEXT(" The Actor starts from (0, 0, 0) "));
}

// Called every frame
void AMoveRandomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bHasPrintedSummary) return;

	if (CurrentStep == TotalSteps)
	{
		// �̵� �� �������� �� �̵��Ÿ��� �̺�Ʈ �߻� Ƚ�� ���
		PrintSummary();
		bHasPrintedSummary = true;
		return;
	}

	ElapsedTime += DeltaTime;

	if (ElapsedTime >= 2.0f) // 2�ʸ��� Step ȣ��
	{
		ElapsedTime = 0.f;
		Step();
	}
}

void AMoveRandomActor::Step()
{
	if (RMovementController)
	{

		FVector PreviousPosition = CurrentPosition; // ���� ��ǥ ����

		// 50% Ȯ���� �̺�Ʈ �߻� ���� Ȯ�� 
		if (EventGenerator && EventGenerator->ShouldTriggerEvent())
		{
			EventCount++;
			UE_LOG(LogTemp, Log, TEXT("Event Triggered! Jump! Step's generated between 1 ~ 10"));
			
			CurrentPosition = RMovementController->RandomJump(CurrentPosition);
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Event not Triggered! Normal Step"));
			CurrentPosition = RMovementController->Move(CurrentPosition);

		}

		float DistanceMoved = FVector::Distance(PreviousPosition, CurrentPosition); // ���� ��ǥ�� ���� ��ǥ ������ �Ÿ� ���
		TotalDistance += DistanceMoved; // �� �̵� �Ÿ� ������Ʈ
		CurrentStep++;

		UE_LOG(LogTemp, Log, TEXT("%d Position : X=%.1f, Y=%.1f \n Distance Moved: % f"), CurrentStep, CurrentPosition.X, CurrentPosition.Y, DistanceMoved);

		SetActorLocation(CurrentPosition);
	}
}

void AMoveRandomActor::PrintSummary()
{
	UE_LOG(LogTemp, Log, TEXT("=========================================================="));
	UE_LOG(LogTemp, Log, TEXT("The Actor stopped moving"));
	UE_LOG(LogTemp, Log, TEXT(" Total Distance : % f, Total Events Triggered : % d"), TotalDistance, EventCount);
	UE_LOG(LogTemp, Log, TEXT("=========================================================="));
}