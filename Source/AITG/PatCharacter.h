// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AITG_API APatCharacter : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "APatCharacter")
	TArray<AActor*> PatrolPoints;
};
