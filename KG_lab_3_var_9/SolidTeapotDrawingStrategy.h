#pragma once
#include "ITeapotDrawingStrategy.h"

class SolidTeapotDrawingStrategy : public ITeapotDrawingStrategy
{
	// Inherited via TeapotDrawingStrategy
	void drawTeapot(const GLfloat teapotSize) override;
};

