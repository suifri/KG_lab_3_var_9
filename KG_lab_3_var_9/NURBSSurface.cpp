#include "NURBSSurface.h"

NURBSSurface::NURBSSurface()
	:nurbs{gluNewNurbsRenderer()}
{
	gluNurbsProperty(this->nurbs, GLU_SAMPLING_TOLERANCE, 25.0);
	gluNurbsProperty(this->nurbs, GLU_DISPLAY_MODE, GLU_OUTLINE_POLYGON);
	this->initSurface();
}

NURBSSurface::~NURBSSurface()
{
	gluDeleteNurbsRenderer(this->nurbs);
}

void NURBSSurface::initSurface()
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
				*(*(*(this->controlPoints + u) + v) + 2) = 1.5;
			else
				*(*(*(this->controlPoints + u) + v) + 2) = -1.0;

			*(*(*(this->controlPoints + u) + v) + 3) = 1.0;
		}
	}
}

void NURBSSurface::display()
{
	GLfloat knots[]{ 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };

	GLint i{ 0 };
	GLint j{ 0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(330.0f, 1.0f, 0.0f, 0.0f);
	glScalef(0.5f, 0.5f, 0.5f);

	gluBeginSurface(this->nurbs);
	glColor3f(.2, 0.5, 0.7);
	gluNurbsSurface(this->nurbs, 8, knots, 8, knots, 4 * 4, 4, **this->controlPoints, 4, 4, GL_MAP2_VERTEX_4);
	gluEndSurface(this->nurbs);

	glPopMatrix();
}
