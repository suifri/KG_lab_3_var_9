#include "InterpolatedTeapotDrawingStrategy.h"

void InterpolatedTeapotDrawingStrategy::drawTeapot(const GLfloat teapotSize)
{
	glShadeModel(GL_SMOOTH);
	glutSolidTeapot(teapotSize);
}
