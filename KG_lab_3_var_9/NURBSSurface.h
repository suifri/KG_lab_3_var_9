#pragma once
#include <GL/glut.h>

class NURBSSurface
{
private:
	GLfloat controlPoints[4][4][4];
	GLUnurbsObj* nurbs;

public:
	
	NURBSSurface();
	~NURBSSurface();

	void initSurface();
	void display();
};

