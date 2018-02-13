//Based on code provided in lecture 12 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into updateForces method from GameObject to Circle object
//-Properties within method now take from circle objects instead of game objects

#include "Gravity.h"

void Gravity::updateForce(Circle * circle, float dt)
{
	circle->addForce(gravity*circle->getInverseMass()); //add the gravity force to the passed in object
}
