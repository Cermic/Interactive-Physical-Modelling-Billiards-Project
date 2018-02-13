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


using namespace glm;
using namespace std;

class Segment
{
private:
	//declare necessary segment properties
	vec2 normal;
	float d;
	vec2 position1;
	vec2 position2;
	vec2 midPoint;
	int id;
public:
	Segment(glm::vec2 point, glm::vec2 vector, vec2 normal, int id);
	virtual ~Segment() {};

	//relevant getters for segment properties
	vec2 getPosition1() { return position1; }
	vec2 getPosition2() { return position2; }
	vec2 getMidPoint() { return midPoint; }
	vec2 getNormal() { return normal; }
	vec2 getNormalizedNormal() { return glm::normalize(normal); }
	int getID() { return id; }
	float getD() { return d; }

	void draw(int width, int height);  //draw method for handling segment drawing
};