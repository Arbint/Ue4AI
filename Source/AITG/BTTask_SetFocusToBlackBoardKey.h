// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_SetFocusToBlackBoardKey.generated.h"

/**
 * 
 */
UCLASS()
class AITG_API UBTTask_SetFocusToBlackBoardKey : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
public:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FBlackboardKeySelector FocusKey;
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	bool bClearFocus;
};
