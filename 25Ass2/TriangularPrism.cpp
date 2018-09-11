#include "TriangularPrism.h"

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

#include <math.h>
#define PI 3.14159265358979323846

Triangle::Triangle() {

}

Triangle::Triangle(float alen, float blen, float angle, float depth) {
	Alen = alen;
	Blen = blen;
	Angle = angle * PI / (180);
	Depth = depth;

}

void Triangle::draw() {
	glPushMatrix();

	glColor3f(red, green, blue);
	glTranslatef(x, y, z);
	glRotatef(-rotation, 0, 1, 0);

	glBegin(GL_TRIANGLES);//front
	glVertex3f(Alen / 2, 0.0, -Depth / 2);//vertex 1
	glVertex3f(-Alen / 2, 0.0, -Depth / 2);//vertex 2
	glVertex3f(-Alen / 2 + Blen * cos(Angle), Blen*sin(Angle), -Depth / 2);//vertex 3
	glEnd();

	glBegin(GL_TRIANGLES);//behind
	glVertex3f(Alen / 2, 0.0, Depth / 2);//vertex 4
	glVertex3f(-Alen / 2, 0.0, Depth / 2);//vertex 5
	glVertex3f(-Alen / 2 + Blen * cos(Angle), Blen*sin(Angle), Depth / 2);//vertex 6
	glEnd();


	glBegin(GL_QUADS);//connect 1,2,5,4
	glVertex3f(Alen / 2, 0.0, -Depth / 2);//vertex 1
	glVertex3f(-Alen / 2, 0.0, -Depth / 2);//vertex 2
	glVertex3f(-Alen / 2, 0.0, Depth / 2);//vertex 5
	glVertex3f(Alen / 2, 0.0, Depth / 2);//vertex 4
	glEnd();



	glBegin(GL_QUADS);//connect 2,3,6,5
	glVertex3f(-Alen / 2, 0.0, -Depth / 2);//vertex 2
	glVertex3f(-Alen / 2 + Blen * cos(Angle), Blen*sin(Angle), -Depth / 2);//vertex 3
	glVertex3f(-Alen / 2 + Blen * cos(Angle), Blen*sin(Angle), Depth / 2);//vertex 6
	glVertex3f(-Alen / 2, 0.0, Depth / 2);//vertex 5
	glEnd();


	glBegin(GL_QUADS);//connect 4,1,3,6
	glVertex3f(Alen / 2, 0.0, Depth / 2);//vertex 4
	glVertex3f(Alen / 2, 0.0, -Depth / 2);//vertex 1
	glVertex3f(-Alen / 2 + Blen * cos(Angle), Blen*sin(Angle), -Depth / 2);//vertex 3
	glVertex3f(-Alen / 2 + Blen * cos(Angle), Blen*sin(Angle), Depth / 2);//vertex 6
	glEnd();

	glPopMatrix();
}


Triangle::~Triangle() {

}