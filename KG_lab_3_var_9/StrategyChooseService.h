#pragma once
#include "InterpolatedTeapotDrawingStrategy.h"
#include "SolidTeapotDrawingStrategy.h"
#include "WireTeapotDrawingStrategy.h"
#include "DRAWING_STRATEGY.h"

static class StrategyChooseService
{
public:
	static ITeapotDrawingStrategy* getStrategy(const DRAWING_STRATEGY strategy = DRAWING_STRATEGY::SOLID) noexcept;
};

