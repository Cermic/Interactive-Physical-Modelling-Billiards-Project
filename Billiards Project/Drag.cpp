//Based on code provided in lecture 13 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into updateForces method from GameObject to Circle object
//-Properties within method now take from circle objects instead of game objects
#include "Drag.h"

void Drag::updateForce(Circle * circle, float dt)
{
	vec2 drag = circle->getVelocity(); //drag force calculated from the circles velocity
	float dragCoeff = length(drag); //magnitude of drag force calculated from the magnitude of velocity
	dragCoeff = k1 * dragCoeff + k2 * dragCoeff*dragCoeff; //multiply dragcoefficent by delcared factors to get final drag coefficent
	if (length(drag) != 0) //if the magnitude of the drag force isn't 0
		drag = -dragCoeff * glm::normalize(drag); //set drag force to the magnitude * normalized direction
	circle->addForce(drag); //apply the drag force

}
