#ifndef MTRN3500_TRI_PRISM_H
#define MTRN3500_TRI_PRISM_H

#include "Shape.hpp"

using namespace std;

class Triangle : public Shape {
protected:
	float Alen;
	float Blen;
	float Angle;
	float Depth;
public:
	Triangle();
	Triangle(float alen, float blen, float angle, float depth);
	void draw();
	~Triangle();
};

#endif