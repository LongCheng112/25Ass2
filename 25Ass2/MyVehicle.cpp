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

MyVehicle::MyVehicle()
{
	ShapeInit part;
	model.remoteID = 0;
	
	part.type = RECTANGULAR_PRISM;
	part.params.rect.xlen = 5;
	part.params.rect.ylen = 2;
	part.params.rect.zlen = 1;
	part.xyz[0] = -3;
	part.xyz[1] = 6;
	part.xyz[2] = 0;
	part.rotation = 90;
	part.rgb[0] = 0;
	part.rgb[1] = 1;
	part.rgb[2] = 1;
	model.shapes.push_back(part);

	part.type = TRIANGULAR_PRISM;
	part.params.tri.alen = 4;
	part.params.tri.blen = 3;
	part.params.tri.depth = 8;
	part.params.tri.angle = 30;
	part.xyz[0] = -4;
	part.xyz[1] = 7;
	part.xyz[2] = 0;
	part.rotation = 0;
	part.rgb[0] = 0;
	part.rgb[1] = 1;
	part.rgb[2] = 0;
	model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.radius = 2;
	part.params.cyl.depth = 1;
	part.params.cyl.isRolling = 1;
	part.params.cyl.isSteering = 1;
	part.xyz[0] = 4;
	part.xyz[1] = 0;
	part.xyz[2] = 3.5;
	part.rotation = 0;
	part.rgb[0] = 1;
	part.rgb[1] = 0;
	part.rgb[2] = 0;
	model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.radius = 2;
	part.params.cyl.depth = 1;
	part.params.cyl.isRolling = 1;
	part.params.cyl.isSteering = 1;
	part.xyz[0] = 4;
	part.xyz[1] = 0;
	part.xyz[2] = -3.5;
	part.rotation = 0;
	part.rgb[0] = 1;
	part.rgb[1] = 0;
	part.rgb[2] = 0;
	model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.radius = 2;
	part.params.cyl.depth = 1;
	part.params.cyl.isRolling = 1;
	part.params.cyl.isSteering = 1;
	part.xyz[0] = -4;
	part.xyz[1] = 0;
	part.xyz[2] = 3.5;
	part.rotation = 0;
	part.rgb[0] = 1;
	part.rgb[1] = 0;
	part.rgb[2] = 0;
	model.shapes.push_back(part);

	part.type = CYLINDER;
	part.params.cyl.radius = 2;
	part.params.cyl.depth = 1;
	part.params.cyl.isRolling = 1;
	part.params.cyl.isSteering = 1;
	part.xyz[0] = -4;
	part.xyz[1] = 0;
	part.xyz[2] = -3.5;
	part.rotation = 0;
	part.rgb[0] = 1;
	part.rgb[1] = 0;
	part.rgb[2] = 0;
	model.shapes.push_back(part);

	part.type = TRAPEZOIDAL_PRISM;
	part.params.trap.alen = 12;
	part.params.trap.blen = 6;
	part.params.trap.height = 4;
	part.params.trap.aoff = 1;
	part.params.trap.depth = 7;
	part.xyz[0] = 0;
	part.xyz[1] = 2;
	part.xyz[2] = 0;
	part.rotation = 0;
	part.rgb[0] = 0;
	part.rgb[1] = 0;
	part.rgb[2] = 1;
	model.shapes.push_back(part);


	//fillShapes(); Long I think you need to define this function

}

MyVehicle::~MyVehicle()
{

}

VehicleModel MyVehicle::GetModel()
{
	return model;
}

/*void MyVehicle::fillShapes()
{
	Long please fill this out
}*/

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
	Cylinder WheelFL(2, 1);
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
	Cylinder WheelFR(2, 1);
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
	Cylinder WheelBL(2, 1);
	WheelBL.setRotation(0);
	WheelBL.setPosition(-4, 0, 3.5);
	WheelBL.setColor(1, 0, 0);
	WheelBL.draw();
	
	// draws back right wheel
	Cylinder WheelBR(2, 1);
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
