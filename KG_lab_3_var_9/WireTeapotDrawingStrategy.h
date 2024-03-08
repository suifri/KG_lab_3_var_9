#pragma once
#include "ITeapotDrawingStrategy.h"

class WireTeapotDrawingStrategy : public ITeapotDrawingStrategy
{
	// Inherited via TeapotDrawingStrategy
	void drawTeapot(const GLfloat teapotSize) override;
};

