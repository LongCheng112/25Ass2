#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Shape.hpp"

class TrapezoidalPrism : public Shape {
protected:
	double aLength;
	double bLength;
	double offset;
	double height;
	double depth;

public:
	TrapezoidalPrism();
	TrapezoidalPrism(double aLength, double bLength, double offset, double height, double depth);
	~TrapezoidalPrism();

	void draw();
};