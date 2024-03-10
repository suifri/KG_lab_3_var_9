#include <GL/freeglut.h>
#include "Teapot.h"
#include "NURBSSurface.h"
#include "BSpline.h"
#include "TrimmedBSpline.h"

const GLfloat lightPosition[] = { 0.0, 5.0, 5.0, 1.0 };
const GLfloat lightAmbient[] = { 0.2, 0.2, 0.2, 1.0 };
const GLfloat lightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat lightColor[] = { 0.5, 0.5, .0, 1.0 };

const GLint initialWidth = 500;
const GLint initialHeight = 500;

Teapot* teapot = new Teapot();
NURBSSurface* nurbs = new NURBSSurface();
BSpline* bSpline = new BSpline();
TrimmedBSpline* trim = new TrimmedBSpline();

GLint displayChoice = 0;
GLboolean isPerspective{ true };

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	if (isPerspective == false)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-5, 5, -5, 5, -5, 5);
	}
	else 
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, 1, 2, 10);
		gluLookAt(0.0, 0.0, 5.0,
				0.0, 0.0, 0.0,
				0.0, 1.0, 0.0);
	}

	switch (displayChoice)
	{
	case 0:
		teapot->display();
		break;
	case 1:
		bSpline->display();
		break;
	case 2:
		nurbs->display();
		break;
	case 3:
		trim->display();
	default:
		break;
	};

	glutSwapBuffers();
}

void reshape(const GLint width, const GLint height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	gluPerspective(45.0, static_cast<GLfloat>(width) / static_cast<GLfloat>(height), 0.1, 100.);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void)
{
	GLfloat matDiffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat matSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat matShininess[] = { 100.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void mainMenuHandler(const GLint choice)
{
	switch (choice)
	{
	case 0:
		displayChoice = 0;
		break;
	case 1:
		displayChoice = 1;//B-Spline
		break;
	case 2: 
		displayChoice = 2;//NURBS-surface
		break;
	case 3:
		displayChoice = 3;
		break;
	case 4:
		isPerspective = true;
		break;
	case 5:
		isPerspective = false;
		break;
	default:
		break;
	}
}

void subMenuHandler(const GLint choice)
{
	switch (choice)
	{
	case 0:
		teapot->setTeapotDrawingStrategy();
		break;
	case 1:
		teapot->setTeapotDrawingStrategy(DRAWING_STRATEGY::INTERPOLATED);
		break;
	case 2:
		teapot->setTeapotDrawingStrategy(DRAWING_STRATEGY::WIRE);
	default:
		break;
	}
}

void bSplineSubMenuHandler(const GLint choice)
{
	delete trim;

	switch (choice)
	{
	case 0:
		trim = new TrimmedBSpline();
		break;
	case 1:
		trim = new TrimmedBSpline(SPLINE_TYPE::OUTLINE_POLYGON);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(initialWidth, initialHeight);
	glutCreateWindow(*argv);
	init();
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	int teapotSubMenu = glutCreateMenu(subMenuHandler);
	glutAddMenuEntry("Solid", 0);
	glutAddMenuEntry("Interpolated", 1);
	glutAddMenuEntry("Wire", 2);

	int bSplineSubMenu = glutCreateMenu(bSplineSubMenuHandler);
	glutAddMenuEntry("Fill", 0);
	glutAddMenuEntry("Wire octahedrons", 1);

	glutCreateMenu(mainMenuHandler);
	glutAddMenuEntry("Teapot", 0);
	glutAddMenuEntry("B-Spline", 1);
	glutAddMenuEntry("NURBS-Surface", 2);
	glutAddMenuEntry("Trimmed B-spline", 3);
	glutAddSubMenu("Teapot texture", teapotSubMenu);
	glutAddSubMenu("Trimmed B-spline texture", bSplineSubMenu);
	glutAddMenuEntry("Perspective", 4);
	glutAddMenuEntry("Ortho", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

	return 0;
}