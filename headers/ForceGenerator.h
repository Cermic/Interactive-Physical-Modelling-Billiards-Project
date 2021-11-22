//Based on code provided in lecture 12 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into updateForces method from GameObject to Circle object

#pragma once
#include "Circle.h"

class ForceGenerator //virtual class to declare necessary update method for any force
{

public:
	virtual ~ForceGenerator() {}
	virtual void updateForce(Circle * circle, float dt) = 0;
};
