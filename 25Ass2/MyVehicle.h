#pragma once

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <vector>

#include "Shape.hpp"
#include "Vehicle.hpp"
#include "RectangularPrism.h"
#include "TriangularPrism.h"
#include "Cylinder.h"
#include "TrapezoidalPrism.h"


class MyVehicle : public Vehicle {
protected:

	VehicleModel model;

public:
	MyVehicle();
	~MyVehicle();

	VehicleModel GetModel();

	//void fillShapes();

	void draw();
};

