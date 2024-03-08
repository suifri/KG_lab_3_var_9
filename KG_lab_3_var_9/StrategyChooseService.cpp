#include "StrategyChooseService.h"

ITeapotDrawingStrategy* StrategyChooseService::getStrategy(const DRAWING_STRATEGY strategy) noexcept
{
	ITeapotDrawingStrategy* result = nullptr;

	switch (strategy)
	{
	case DRAWING_STRATEGY::SOLID:
		result = new SolidTeapotDrawingStrategy();
		break;
	case DRAWING_STRATEGY::WIRE:
		result = new WireTeapotDrawingStrategy();
		break;
	case DRAWING_STRATEGY::INTERPOLATED:
		result = new InterpolatedTeapotDrawingStrategy();
		break;
	default:
		break;
	}

	return result;
}
