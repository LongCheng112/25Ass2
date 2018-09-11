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

#include "TrapezoidalPrism.h"

TrapezoidalPrism::TrapezoidalPrism()
{

}

TrapezoidalPrism::TrapezoidalPrism(double aLength, double bLength, double offset, double height, double depth)
{
	this->aLength = aLength;
	this->bLength = bLength;
	this->offset = offset;
	this->height = height;
	this->depth = depth;
}

TrapezoidalPrism::~TrapezoidalPrism()
{

}

void TrapezoidalPrism::draw()
{
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
	glTranslated(-aLength/2, 0, -depth / 2);

	// Drawing front trapezium
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(offset, height, 0);
	glVertex3d(offset + bLength, height, 0);
	glVertex3d(aLength, 0, 0);
	glEnd();

	// Drawing back trapezium
	glBegin(GL_QUADS);
	glVertex3d(0, 0, depth);
	glVertex3d(offset, height, depth);
	glVertex3d(offset + bLength, height, depth);
	glVertex3d(aLength, 0, depth);
	glEnd();

	// Drawing base (or bottom face)
	glBegin(GL_QUADS);
	glVertex3d(0, 0, 0);
	glVertex3d(aLength, 0, 0);
	glVertex3d(aLength, 0, depth);
	glVertex3d(0, 0, depth);
	glEnd();

	// Drawing top face
	glBegin(GL_QUADS);
	glVertex3d(offset, height, 0);
	glVertex3d(offset, height, depth);
	glVertex3d(offset + bLength, height, depth);
	glVertex3d(offset + bLength, height, 0);
	glEnd();

	// Drawing left side
	glBegin(GL_QUADS);
	glVertex3d(offset, height, 0);
	glVertex3d(offset, height, depth);
	glVertex3d(0, 0, depth);
	glVertex3d(0, 0, 0);
	glEnd();

	// Drawing right side
	glBegin(GL_QUADS);
	glVertex3d(offset + bLength, height, depth);
	glVertex3d(offset + bLength, height, 0);
	glVertex3d(aLength, 0, 0);
	glVertex3d(aLength, 0, depth);
	glEnd();

	glPopMatrix();
}
