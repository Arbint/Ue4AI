// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_SetFocusToBlackBoardKey.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"


EBTNodeResult::Type UBTTask_SetFocusToBlackBoardKey::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	AAIController* AIC = OwnerComp.GetAIOwner();
	AActor* FocusActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FocusKey.SelectedKeyName));
	if (bClearFocus && AIC)
	{
		AIC->ClearFocus(EAIFocusPriority::Gameplay);
	}
	else if (AIC && FocusActor)
	{
		AIC->SetFocus(FocusActor);
	}
	return EBTNodeResult::Succeeded;
}
