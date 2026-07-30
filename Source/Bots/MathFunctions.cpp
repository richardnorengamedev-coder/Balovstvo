// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MathFunctions.h"

float UMathFunctions::EaseOutExpo(float Alpha)
{
    return Alpha >= 1.0f
        ? 1.0f
        : 1.0f - FMath::Pow(2.0f, -10.0f * Alpha);
}

FVector UMathFunctions::SpiralPoint(const FVector& Origin, const FVector& Axis, const FSpiralSettings& Settings, float Alpha)
{
    // Clamp alpha
    const float A = FMath::Clamp(Alpha, 0.0f, 1.0f);

    // Normalize axis, fallback to Up if zero
    FVector AxisNorm = Axis.GetSafeNormal();
    if (AxisNorm.IsNearlyZero())
    {
        AxisNorm = FVector::UpVector;
    }

    // Build orthonormal basis (X,Y) perpendicular to AxisNorm
    FVector Arbitrary = FMath::Abs(AxisNorm.Z) < 0.99f ? FVector::UpVector : FVector::RightVector;
    FVector BasisX = FVector::CrossProduct(Arbitrary, AxisNorm).GetSafeNormal();
    // If cross gave zero (very unlikely), fallback
    if (BasisX.IsNearlyZero())
    {
        Arbitrary = FVector::ForwardVector;
        BasisX = FVector::CrossProduct(Arbitrary, AxisNorm).GetSafeNormal();
    }
    FVector BasisY = FVector::CrossProduct(AxisNorm, BasisX).GetSafeNormal();

    // Radius interpolation
    const float Radius = FMath::Lerp(Settings.StartRadius, Settings.EndRadius, A);

    // Angle in radians: start angle + turns * 360deg * alpha, clockwise support
    const float Direction = Settings.bClockwise ? -1.0f : 1.0f;
    const float AngleDeg = Settings.StartAngleDeg + Direction * Settings.Turns * 360.0f * A;
    const float AngleRad = FMath::DegreesToRadians(AngleDeg);

    // Local XY in plane
    const float LocalX = FMath::Cos(AngleRad) * Radius;
    const float LocalY = FMath::Sin(AngleRad) * Radius;

    // Vertical offset along axis
    const float HeightOffset = Settings.Height * A;

    // Compose world position
    const FVector Point = Origin + BasisX * LocalX + BasisY * LocalY + AxisNorm * HeightOffset;
    return Point;
}
