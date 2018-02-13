//Based on code provided in lecture 12 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into updateForces method from GameObject to Circle object
//-Properties within method now take from circle objects instead of game objects
#pragma once
#include"Circle.h"
#include "ForceGenerator.h"
#include <glm\glm\glm.hpp>
#include <float.h>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <glm\glm\ext.hpp>


using namespace glm;

class Drag : public ForceGenerator
{
private:
	//drag factors
	float k1;
	float k2;
public:
	Drag(float k1, float k2) :k1(k1), k2(k2) {}
	virtual ~Drag() {}
	void updateForce(Circle * circle, float dt); //method for applying drag to circles
};
