// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Choose_next_waypoint.h"




EBTNodeResult::Type UBTTask_Choose_next_waypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("Hey I am happy now"));
	return EBTNodeResult::Succeeded;
}
