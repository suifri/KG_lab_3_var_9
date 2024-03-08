#pragma once
#include "StrategyChooseService.h"

class Teapot
{
private:
	GLfloat teapotSize;
	ITeapotDrawingStrategy* strategy;
public:

	Teapot(const GLfloat teapotSize = 1.0, ITeapotDrawingStrategy* strategy = new SolidTeapotDrawingStrategy());
	void setTeapotDrawingStrategy(const DRAWING_STRATEGY strategy = DRAWING_STRATEGY::SOLID) noexcept;
	void display() const;
};

