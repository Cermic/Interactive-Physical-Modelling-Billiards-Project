//Based on code provided in lecture 13 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into class from GameObjects to Circle objects
//-Properties within methods now take from circle objects instead of game objects

#pragma once
#include <glm\glm\glm.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <float.h>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <glm\glm\ext.hpp>
#include "Circle.h"

using namespace std;
using namespace glm;



class CollisionReaction {
private:
	float ResolveRestingContact(float dt); //method for resolving collisions involving a stationary object
	void  ResolveVelocity(float dt); //method to resolve velocity of objects in a collision
	void  ResolveInterpenetration(float dt); //method to resolve interpenetration of objects in a collision
	vector<Circle*> obj; //vector of circles, will contain colliding circles

public:
	//public properties/methods
	float restitution; //restiution of objects
	float penetration; //penetration of objects
	vec2 contactNormal; //contactNormal of colliding objects
	void Resolve(float dt); //resolv method containg calls to private resolve methods
	float ComputeSeparatingVelocity() const; //method for calculating what the sepearting velocity will be of two colliding objects
	void setObjects(vector<Circle*>& objects); //used to set objects for obtaining relevant properties of circles invlved in collision

											   //setters for necessary values to correct resolve collisions
	void setPenetration(float pen);
	void setRestiution(float res);
	void setContactNormal(vec2 normal);
};

