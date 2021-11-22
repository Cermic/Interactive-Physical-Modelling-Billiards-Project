//Based on code provided in lecture 12 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into updateForces method from GameObject to Circle object
//-Properties within method now take from circle objects instead of game objects

#pragma once
#include "Circle.h"
#include "ForceGenerator.h"

class Gravity : public ForceGenerator
{
private:
	vec3 gravity;  //gravity force
public:
	Gravity(const vec3& gravity) :gravity(gravity) {}
	virtual ~Gravity() {}
	void updateForce(Circle* circle, float dt); //method for updating gravity force
};