#pragma once
#include "ITeapotDrawingStrategy.h"

class InterpolatedTeapotDrawingStrategy : public ITeapotDrawingStrategy
{
	// Inherited via ITeapotDrawingStrategy
	void drawTeapot(const GLfloat teapotSize) override;
};

