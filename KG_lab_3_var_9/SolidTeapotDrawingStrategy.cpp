#include "SolidTeapotDrawingStrategy.h"

void SolidTeapotDrawingStrategy::drawTeapot(const GLfloat teapotSize)
{
	glShadeModel(GL_FLAT);
	glutSolidTeapot(teapotSize);
}
