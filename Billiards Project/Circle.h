/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once

#include <glm\glm\glm.hpp>
#include <float.h>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <glm\glm\ext.hpp>
#include <GL\glut.h>
#include <iostream>

using namespace glm;
using namespace std;

class Circle
{
private:
	vec2 position;
	float radius;
	vec2 velocity;
	vec2 acceleration;
	void VelocityVerletSolver(float dt);
	float mass; // use to ask the user for the mass of the balls at the start of the program.
	float invMass;
	vec2 forceAccum;
	int id = 0;
	GLfloat red;
	GLfloat green;
	GLfloat blue;
	// properties declared
public:
	Circle(vec2& centrePoint, float radius, vec2& velocity, vec2& acceleration, float invMass,vec2 forceAccum, vec3 col, int id) 
		:position(centrePoint), radius(radius), velocity(velocity), acceleration(acceleration),invMass(invMass),forceAccum(forceAccum),red(col.x), green(col.y), blue(col.z), id(id){};

	virtual ~Circle() {};
	vec2 getPosition() { return position; }
	float getRadius(){ return radius; }
	vec2 getVelocity() { return velocity; }
	vec2 getAcceleration() { return acceleration; }

	void setAccelration(vec2 a);
	void setPosition(vec2 p);
	void setVelocity(vec2 v);
	void setXVelocity(float x);
	void setYVelocity(float y);

	vec2 getForceAccum() { return forceAccum; }
	vec2 setForceAccum();

	float getInverseMass() { return invMass; }
	int getId() { return id; }
	// appropriate setters and getters for changing properties

	void clearAccumulator();
	void addForce(const vec2& force);
	
	void update(float dt);
	void draw(int width, int height);
};