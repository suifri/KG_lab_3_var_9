#include "WireTeapotDrawingStrategy.h"

void WireTeapotDrawingStrategy::drawTeapot(const GLfloat teapotSize)
{
	glutWireTeapot(teapotSize);
}
