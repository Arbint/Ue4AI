// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Choose_next_waypoint.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UBTTask_Choose_next_waypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	if (BlackBoardComp)
	{
		auto WaypointIndexVal = BlackBoardComp->GetValueAsInt(WaypointIndexKey.SelectedKeyName);
		UE_LOG(LogTemp, Warning, TEXT("Waypoint, index: %i"), WaypointIndexVal);
		return EBTNodeResult::Succeeded;

	}
	else
	{
		return EBTNodeResult::Failed;
	}
}
