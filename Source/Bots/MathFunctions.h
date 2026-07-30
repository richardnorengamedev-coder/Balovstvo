// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MathFunctions.generated.h"

USTRUCT(BlueprintType)
struct FSpiralSettings
{
    GENERATED_BODY()

    // Radius at Alpha = 0
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spiral")
    float StartRadius = 100.0f;

    // Radius at Alpha = 1
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spiral")
    float EndRadius = 100.0f;

    // Number of full turns over Alpha = 0..1
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spiral")
    float Turns = 1.0f;

    // Total translation along the axis over Alpha = 0..1
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spiral")
    float Height = 0.0f;

    // Start angle in degrees
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spiral")
    float StartAngleDeg = 0.0f;

    // If true the spiral winds clockwise when looking along the axis direction
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spiral")
    bool bClockwise = false;

    FSpiralSettings() {}
};

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

    /**
     * Получает точку на спирали.
     * - Origin: центр/начало спирали
     * - Axis: ось спирали (направление "вверх" для подъёма)
     * - Settings: параметры спирали (радиусы, витки, высота и т.п.)
     * - Alpha: 0..1 (положение вдоль спирали)
     */
    UFUNCTION(BlueprintPure, Category = "Math|Spiral", meta=(DisplayName = "Spiral Point"))
    static FVector SpiralPoint(const FVector& Origin, const FVector& Axis, const FSpiralSettings& Settings, float Alpha);
};
