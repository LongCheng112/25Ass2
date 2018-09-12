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

#include "MyVehicle.h"
#include "Messages.hpp"
#include "RectangularPrism.h"
#include "TriangularPrism.h"
#include "Cylinder.h"
#include "TrapezoidalPrism.h"
#include "Shape.hpp"


MyVehicle::MyVehicle()
{
	
	model.remoteID = 0;
	ShapeInit middle;
	middle.type = RECTANGULAR_PRISM;
	middle.params.rect.xlen = 5;
	middle.params.rect.ylen = 2;
	middle.params.rect.zlen = 1;
	middle.xyz[0] = -3;
	middle.xyz[1] = 6;
	middle.xyz[2] = 0;
	middle.rotation = 90;
	middle.rgb[0] = 0;
	middle.rgb[1] = 1;
	middle.rgb[2] = 1;
	model.shapes.push_back(middle);

	ShapeInit top;
	top.type = TRIANGULAR_PRISM;
	top.params.tri.alen = 4;
	top.params.tri.blen = 3;
	top.params.tri.depth = 8;
	top.params.tri.angle = 30;
	top.xyz[0] = -4;
	top.xyz[1] = 7;
	top.xyz[2] = 0;
	top.rotation = 0;
	top.rgb[0] = 0;
	top.rgb[1] = 1;
	top.rgb[2] = 0;
	model.shapes.push_back(top);

	ShapeInit c1;
	c1.type = CYLINDER;
	c1.params.cyl.radius = 2;
	c1.params.cyl.depth = 1;
	c1.params.cyl.isRolling = 1;
	c1.params.cyl.isSteering = 1;
	c1.xyz[0] = 4;
	c1.xyz[1] = 0;
	c1.xyz[2] = 3.5;
	c1.rotation = 0;
	c1.rgb[0] = 1;
	c1.rgb[1] = 0;
	c1.rgb[2] = 0;
	model.shapes.push_back(c1);

	ShapeInit c2;
	c2.type = CYLINDER;
	c2.params.cyl.radius = 2;
	c2.params.cyl.depth = 1;
	c2.params.cyl.isRolling = 1;
	c2.params.cyl.isSteering = 1;
	c2.xyz[0] = 4;
	c2.xyz[1] = 0;
	c2.xyz[2] = -3.5;
	c2.rotation = 0;
	c2.rgb[0] = 1;
	c2.rgb[1] = 0;
	c2.rgb[2] = 0;
	model.shapes.push_back(c2);

	ShapeInit c3;
	c3.type = CYLINDER;
	c3.params.cyl.radius = 2;
	c3.params.cyl.depth = 1;
	c3.params.cyl.isRolling = 1;
	c3.params.cyl.isSteering = 1;
	c3.xyz[0] = -4;
	c3.xyz[1] = 0;
	c3.xyz[2] = 3.5;
	c3.rotation = 0;
	c3.rgb[0] = 1;
	c3.rgb[1] = 0;
	c3.rgb[2] = 0;
	model.shapes.push_back(c3);

	ShapeInit c4;
	c4.type = CYLINDER;
	c4.params.cyl.radius = 2;
	c4.params.cyl.depth = 1;
	c4.params.cyl.isRolling = 1;
	c4.params.cyl.isSteering = 1;
	c4.xyz[0] = -4;
	c4.xyz[1] = 0;
	c4.xyz[2] = -3.5;
	c4.rotation = 0;
	c4.rgb[0] = 1;
	c4.rgb[1] = 0;
	c4.rgb[2] = 0;
	model.shapes.push_back(c4);

	ShapeInit body;
	body.type = TRAPEZOIDAL_PRISM;
	body.params.trap.alen = 12;
	body.params.trap.blen = 6;
	body.params.trap.height = 4;
	body.params.trap.aoff = 1;
	body.params.trap.depth = 7;
	body.xyz[0] = 0;
	body.xyz[1] = 2;
	body.xyz[2] = 0;
	body.rotation = 0;
	body.rgb[0] = 0;
	body.rgb[1] = 0;
	body.rgb[2] = 1;
	model.shapes.push_back(body);

	initialS();

}

MyVehicle::~MyVehicle()
{

}

VehicleModel MyVehicle::GetModel()
{
	return model;
}

void MyVehicle::initialS() {
	int i = 0;
	while (i < model.shapes.size()) {
		model.shapes[i].rotation = 0;
		if (model.shapes[i].type == RECTANGULAR_PRISM) {
			double x_len = model.shapes[i].params.rect.xlen;
			double y_len = model.shapes[i].params.rect.ylen;
			double z_len = model.shapes[i].params.rect.zlen;
			Rectangular* rect = new Rectangular(x_len, y_len, z_len, model.shapes[i].rotation);
			rect->setPosition(model.shapes[i].xyz[0], model.shapes[i].xyz[1], model.shapes[i].xyz[2]);
			rect->setColor(model.shapes[i].rgb[0], model.shapes[i].rgb[1], model.shapes[i].rgb[2]);
			addShape(rect);
		}
		else if (model.shapes[i].type == TRIANGULAR_PRISM) {
			double a_len = model.shapes[i].params.tri.alen;
			double b_len = model.shapes[i].params.tri.blen;
			double angle = model.shapes[i].params.tri.angle;
			Triangle* tri = new Triangle(a_len, b_len);
			tri->Setangle(angle);
			tri->Setdepth(model.shapes[i].params.tri.depth);
			tri->setPosition(model.shapes[i].xyz[0], model.shapes[i].xyz[1], model.shapes[i].xyz[2]);
			tri->setColor(model.shapes[i].rgb[0], model.shapes[i].rgb[1], model.shapes[i].rgb[2]);
			tri->setRotation(model.shapes[i].rotation);
			addShape(tri);
		}
		else if (model.shapes[i].type == TRAPEZOIDAL_PRISM) {
			double a_len = model.shapes[i].params.trap.alen;
			double offset = model.shapes[i].params.trap.aoff;
			double height = model.shapes[i].params.trap.height;
			double depth = model.shapes[i].params.trap.depth;
			TrapezoidalPrism* trap = new TrapezoidalPrism(a_len, offset, height, depth, model.shapes[i].rotation);
			trap->setPosition(model.shapes[i].xyz[0], model.shapes[i].xyz[1], model.shapes[i].xyz[2]);
			trap->setColor(model.shapes[i].rgb[0], model.shapes[i].rgb[1], model.shapes[i].rgb[2]);
			addShape(trap);
		}
		else if (model.shapes[i].type == CYLINDER) {
			double radius = model.shapes[i].params.cyl.radius;
			double depth = model.shapes[i].params.cyl.depth;
			if (model.shapes[i].params.cyl.isRolling == true)
			
			{
				Cylinder* cyl = new Cylinder(radius, depth, model.shapes[i].rotation);
				cyl->setPosition(model.shapes[i].xyz[0], model.shapes[i].xyz[1], model.shapes[i].xyz[2]);
				cyl->setColor(model.shapes[i].rgb[0], model.shapes[i].rgb[1], model.shapes[i].rgb[2]);
				addShape(cyl);
			}
		}
		i++;
	}
}

void MyVehicle::draw()
{
	// move to the vehicle’s local frame of reference
	glPushMatrix();
	positionInGL();

	// draws body of vehicle
	TrapezoidalPrism TrapezoidalPrism(12, 6, 1, 4, 7);
	TrapezoidalPrism.setPosition(0, 2, 0);
	TrapezoidalPrism.setColor(0, 0, 1);
	TrapezoidalPrism.setRotation(0);
	TrapezoidalPrism.draw();
	
	// retrieve the angle of steering
	double steerAngle = getSteering();

	// draws front left wheel
	Cylinder WheelFL(2, 1, true, true);
	if (steerAngle == steering) {
		// adjusts the left wheel if it is being steered
		WheelFL.setRotation(steerAngle);
	}
	else {
		// leaves wheel in default rotation when not being steered
		WheelFL.setRotation(0);
	}
	WheelFL.setPosition(4, 0, 3.5);
	WheelFL.setColor(1, 0, 0);
	WheelFL.draw();

	// draws front right wheel
	Cylinder WheelFR(2, 1, true, true);
	if (steerAngle == steering) {
		WheelFR.setRotation(steerAngle);
	}
	else {
		WheelFR.setRotation(0);
	}
	WheelFR.setPosition(4, 0, -3.5);
	WheelFR.setColor(1, 0, 0);
	WheelFR.draw();
	
	// draws back left wheel
	Cylinder WheelBL(2, 1,true,false);
	WheelBL.setRotation(0);
	WheelBL.setPosition(-4, 0, 3.5);
	WheelBL.setColor(1, 0, 0);
	WheelBL.draw();
	
	// draws back right wheel
	Cylinder WheelBR(2, 1, true, false);
	WheelBR.setRotation(0);
	WheelBR.setPosition(-4, 0, -3.5);
	WheelBR.setColor(1, 0, 0);
	WheelBR.draw();
	
	Rectangular Rectangular(5, 2, 1);
	Rectangular.setRotation(90);
	Rectangular.setPosition(-3, 6, 0);
	Rectangular.setColor(0, 1, 1);
	Rectangular.draw();
	
	Triangle Triangle(4, 3, 30, 8);
	Triangle.setPosition(-4, 7, 0);
	Triangle.setRotation(0);
	Triangle.setColor(0, 1, 0);
	Triangle.draw();
	
	// move back to global frame of reference
	glPopMatrix();	
}
