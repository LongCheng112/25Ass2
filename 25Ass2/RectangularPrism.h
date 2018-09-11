#ifndef MTRN3500_RECT_PRISM_H
#define MTRN3500_RECT_PRISM_H

#include "Shape.hpp"

using namespace std;

class Rectangular : public Shape {
protected:
	double RecLength;
	double RecWidth;
	double RecHeight;

public:
	Rectangular();
	Rectangular(double _length, double _width, double _height);
	void  draw();
	~Rectangular();

};


#endif
