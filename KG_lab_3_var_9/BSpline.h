#pragma once
#include <GL/glut.h>
#include "SPLINE_TYPE.h"

class BSpline
{
protected:
	GLfloat controlPoints[4][4][3];
	GLUnurbsObj* nurbs;

public:
	BSpline(const SPLINE_TYPE type = SPLINE_TYPE::FILL);
	virtual ~BSpline();

	void initSurface();
	void display();
};

