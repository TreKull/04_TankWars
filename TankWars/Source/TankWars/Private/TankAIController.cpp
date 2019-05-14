// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/Actor.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto AIControlledTank = GetAIControlledTank();
	auto PlayerTank = GetPlayerTank();
	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIControlledTank is missing!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIControlledTank: %s"), *AIControlledTank->GetName());
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIControlledTank can't find Player Tank!!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIControlledTank found Player: %s"), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
