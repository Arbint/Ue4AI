// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Choose_next_waypoint.h"
#include "AIController.h"
#include "PatCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UBTTask_Choose_next_waypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent();
	auto AIC = OwnerComp.GetAIOwner();
	APatCharacter* PatCharacter = Cast<APatCharacter>(AIC->GetPawn());
	if (BlackBoardComp && AIC && PatCharacter)
	{
		TArray<AActor*> Waypoints = PatCharacter->PatrolPoints;
		auto WaypointIndexVal = BlackBoardComp->GetValueAsInt(WaypointIndexKey.SelectedKeyName);
		AActor* NextWaypointActor = Waypoints[WaypointIndexVal];
		BlackBoardComp->SetValueAsInt(WaypointIndexKey.SelectedKeyName, (WaypointIndexVal + 1) % (Waypoints.Num()));
		BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName, NextWaypointActor);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}
