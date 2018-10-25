// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_Choose_next_waypoint.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UBTTask_Choose_next_waypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
	AAIController* AIC = OwnerComp.GetAIOwner();
	
	if (BlackBoardComp && AIC && AIC->GetPawn())
	{
		UPatrolRouteComponent* PatrolRouteComp = Cast<UPatrolRouteComponent>(AIC->GetPawn()->GetComponentByClass(UPatrolRouteComponent::StaticClass()));
		if (PatrolRouteComp)
		{
			AActor* NextWayPoint = PatrolRouteComp->GetNextWayPoint();
			if(NextWayPoint)
			{ 
				BlackBoardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolRouteComp->GetNextWayPoint());
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
