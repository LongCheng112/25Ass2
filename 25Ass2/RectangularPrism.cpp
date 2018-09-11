#include "RectangularPrism.h"

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

using namespace std;

Rectangular::Rectangular() {

}

Rectangular::Rectangular(double _length, double _width, double _height) {
	RecLength = _length;
	RecWidth = _width;
	RecHeight = _height;
}


void Rectangular::draw() {
	glPushMatrix();

	glColor3f(red, green, blue);
	glTranslatef(x, y, z);//translate the coordinate system 
	glRotatef(-rotation, 0, 1, 0);


	glBegin(GL_QUADS);//draw bottom side, set right-up vertex as vertex 1, clockwise drawing it
	glVertex3f(RecLength / 2, 0, -RecWidth / 2);//vertex 1
	glVertex3f(-RecLength / 2, 0, -RecWidth / 2);//vertex 2
	glVertex3f(-RecLength / 2, 0, RecWidth / 2);//vertex 3
	glVertex3f(RecLength / 2, 0, RecWidth / 2);//vertex 4
	glEnd();


	glBegin(GL_QUADS);//draw up side,set right-up vertex as vertex 5, clockwise drawing it
	glVertex3f(RecLength / 2, RecHeight, -RecWidth / 2);//vertex 5
	glVertex3f(-RecLength / 2, RecHeight, -RecWidth / 2);//vertex 6
	glVertex3f(-RecLength / 2, RecHeight, RecWidth / 2);//vertex 7
	glVertex3f(RecLength / 2, RecHeight, RecWidth / 2);//vertex 8
	glEnd();

	glBegin(GL_QUADS);//upper surface, connect point 8,4,3,7
	glVertex3f(RecLength / 2, RecHeight, RecWidth / 2);//vertex 8
	glVertex3f(RecLength / 2, 0, RecWidth / 2);//vertex 4
	glVertex3f(-RecLength / 2, 0, RecWidth / 2);//vertex 3
	glVertex3f(-RecLength / 2, RecHeight, RecWidth / 2);//vertex 7
	glEnd();


	glBegin(GL_QUADS);//bottom surface, connect point 5,1,2,6
	glVertex3f(RecLength / 2, RecHeight, -RecWidth / 2);//vertex 5
	glVertex3f(RecLength / 2, 0, -RecWidth / 2);//vertex 1
	glVertex3f(-RecLength / 2, 0, -RecWidth / 2);//vertex 2
	glVertex3f(-RecLength / 2, RecHeight, -RecWidth / 2);//vertex 6
	glEnd();

	glBegin(GL_QUADS);//left surface, connect point 4,1,5,8
	glVertex3f(RecLength / 2, 0, RecWidth / 2);//vertex 4
	glVertex3f(RecLength / 2, 0, -RecWidth / 2);//vertex 1
	glVertex3f(RecLength / 2, RecHeight, -RecWidth / 2);//vertex 5
	glVertex3f(RecLength / 2, RecHeight, RecWidth / 2);//vertex 8
	glEnd();

	glBegin(GL_QUADS);//right surface, connect point 3,2,6,7
	glVertex3f(-RecLength / 2, 0, RecWidth / 2);//vertex 3
	glVertex3f(-RecLength / 2, 0, -RecWidth / 2);//vertex 2
	glVertex3f(-RecLength / 2, RecHeight, -RecWidth / 2);//vertex 6
	glVertex3f(-RecLength / 2, RecHeight, RecWidth / 2);//vertex 7
	glEnd();

	glPopMatrix();
}

Rectangular::~Rectangular() {


}