//Based on code provided in lecture 12 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object in forceRegistration struct to circle from gameObject
//-Changed type of object passed into add and remove methods from GameObject to Circle object
//-Properties within method now take from circle objects instead of game objects

#pragma once
#include "Circle.h"
#include "ForceGenerator.h"
#include <glm\glm.hpp>
#include <float.h>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\ext.hpp>
#include <GL\glut.h>
#include <vector>
using namespace glm;


class ForceRegistry //class for containing list of active forces
{
protected:
	struct ForceRegistration //active force requires the relevant force and the object it is acting upon
	{
		Circle* circle;
		ForceGenerator* fg;
	};
	vector<ForceRegistration> registrations; //list of registered forces
public:
	virtual ~ForceRegistry() {}
	void add(Circle* circle, ForceGenerator* fg); //method to add an active force to the list
	void remove(Circle* circle, ForceGenerator* fg); //method to remove an active force to the list
	void updateForces(float dt); //method to update all registered forces
};

