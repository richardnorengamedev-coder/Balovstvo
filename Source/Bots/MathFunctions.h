// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathFunctions.generated.h"

/**
 * 
 */
UCLASS()
class BOTS_API UMathFunctions : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintPure, Category = "Math|Easing")
    static float EaseOutExpo(float Alpha);
};
