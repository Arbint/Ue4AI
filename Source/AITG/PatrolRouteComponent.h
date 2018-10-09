// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AITG_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolRouteComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PatrolRoute")
	TArray<AActor*> Waypoints;

public:
	UFUNCTION(BlueprintCallable, Category = "PatrolRoute")
	AActor* GetNextWayPoint();
private:
	uint8 NextWayPointIndex;
};
