#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif

#include "Cylinder.h"


Cylinder::Cylinder()
{

}

Cylinder::Cylinder(double radius, double depth)
{
	this->radius = radius;
	this->depth = depth;	

}

Cylinder::~Cylinder()
{

}


void Cylinder::draw() {
	double x = getX();
	double y = getY();
	double z = getZ();

	double red = getRed();
	double green = getGreen();
	double blue = getBlue();

	glPushMatrix();
	positionInGL();
	glColor3d(red, green, blue);

	// Orient shape as shown in 'Server Shapes Specification'
	glTranslated(0, radius, -depth/2);
	
	GLUquadricObj *cylinder = gluNewQuadric();

	// Draw shell of cylinder
	gluCylinder(cylinder, radius, radius, depth, 50, 50);

	// Draw base of cylinder
	gluDisk(cylinder, 0, radius, 50, 1);

	// Draw base at other end of shell
	glTranslated(0, 0, depth);
	gluDisk(cylinder, 0, radius, 50, 1);
	glPopMatrix();
}

