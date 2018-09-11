#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Shape.hpp"

class Cylinder : public Shape {
protected:
	double radius;
	double depth;
	
public:
	Cylinder();
	Cylinder(double radius, double depth);
	~Cylinder();

	void draw();
};