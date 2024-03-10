#include "BSpline.h"

BSpline::BSpline(const SPLINE_TYPE type)
	:nurbs{gluNewNurbsRenderer()}
{
	gluNurbsProperty(this->nurbs, GLU_SAMPLING_TOLERANCE, 25.0);
	type == SPLINE_TYPE::FILL ? gluNurbsProperty(this->nurbs, GLU_DISPLAY_MODE, GLU_FILL) : gluNurbsProperty(this->nurbs, GLU_DISPLAY_MODE, GLU_OUTLINE_POLYGON);

	this->initSurface();
}

BSpline::~BSpline()
{
	gluDeleteNurbsRenderer(this->nurbs);
}

void BSpline::initSurface()
{
	GLint u{ 0 };
	GLint v{ 0 };

	for (u = 0; u < 4; ++u)
	{
		for (v = 0; v < 4; ++v)
		{
			**(*(this->controlPoints + u) + v) = 2.0 * (static_cast<GLfloat>(u) - 1.5);
			*(*(*(this->controlPoints + u) + v) + 1) = 2.0 * (static_cast<GLfloat>(v) - 1.5);

			if ((u == 1 || u == 2) && (v == 1 || v == 2))
				*(*(*(this->controlPoints + u) + v) + 2) = 3.0;
			else
				*(*(*(this->controlPoints + u) + v) + 2) = -3.0;
		}
	}
}

void BSpline::display()
{
	GLfloat knots[]{ 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };

	GLint i{ 0 };
	GLint j{ 0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(330.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(0, 2, 0);

	gluBeginSurface(this->nurbs);
	glColor3f(.2, 0.5, 0.7);
	gluNurbsSurface(this->nurbs, 8, knots, 8, knots, 4 * 3, 3, **this->controlPoints, 4, 4, GL_MAP2_VERTEX_3);
	gluEndSurface(this->nurbs);

	glutPostRedisplay();
}


