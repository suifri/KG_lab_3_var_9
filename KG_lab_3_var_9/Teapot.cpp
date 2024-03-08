#include "Teapot.h"

Teapot::Teapot(const GLfloat teapotSize, ITeapotDrawingStrategy* strategy)
	:teapotSize(teapotSize), strategy(strategy)
{
}

void Teapot::setTeapotDrawingStrategy(const DRAWING_STRATEGY strategy) noexcept
{
	this->strategy = StrategyChooseService::getStrategy(strategy);
}

void Teapot::display() const
{
	glPushMatrix();

	glRotatef(30, .5, .0, .0);
	glColor3f(0.3, 0.4, 0.2);
	this->strategy->drawTeapot();
	glPopMatrix();

	glutPostRedisplay();
}
