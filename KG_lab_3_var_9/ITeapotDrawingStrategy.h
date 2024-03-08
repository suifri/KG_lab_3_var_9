#pragma once
#include <GL/glut.h>

class ITeapotDrawingStrategy
{
public:
	virtual void drawTeapot(const GLfloat teapotSize = 1.0) = 0;
	virtual ~ITeapotDrawingStrategy() = default;
};

