// Fill out your copyright notice in the Description page of Project Settings.

#include "MathFunctions.h"

float UMathFunctions::EaseOutExpo(float Alpha)
{
    return Alpha >= 1.0f
        ? 1.0f
        : 1.0f - FMath::Pow(2.0f, -10.0f * Alpha);
}