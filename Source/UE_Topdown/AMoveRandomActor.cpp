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

	// Random Movement 컨트롤러랑 Event Generator 객체 생성
	RMovementController = NewObject<URandomMovementController>();
	EventGenerator = NewObject<UEventGenerator>();

	// 처음 0,0 으로 시작 
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
		// 이동 다 끝났으면 총 이동거리와 이벤트 발생 횟수 출력
		PrintSummary();
		bHasPrintedSummary = true;
		return;
	}

	ElapsedTime += DeltaTime;

	if (ElapsedTime >= 2.0f) // 2초마다 Step 호출
	{
		ElapsedTime = 0.f;
		Step();
	}
}

void AMoveRandomActor::Step()
{
	if (RMovementController)
	{

		FVector PreviousPosition = CurrentPosition; // 이전 좌표 저장

		// 50% 확률로 이벤트 발생 여부 확인 
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

		float DistanceMoved = FVector::Distance(PreviousPosition, CurrentPosition); // 이전 좌표와 현재 좌표 사이의 거리 계산
		TotalDistance += DistanceMoved; // 총 이동 거리 업데이트
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