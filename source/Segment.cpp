/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "Segment.h"

using namespace std;
using namespace glm;


Segment::Segment(glm::vec2 point, glm::vec2 vector, vec2 normal, int id) : position1(point), position2(vector), midPoint((point.x+ vector.x)/2, (point.y + vector.y) / 2), normal(normal), d(vector.y * point.x - vector.x * point.y), id(id)
{
	//empty constrcutor, all necessary construction done above
}

void Segment::draw(int width, int height)
{
	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height); //set aspectRatio

	//set width and colour
	glLineWidth(5.0);
	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_LINES); //begin drawing using lines to connect vertices

	glVertex2f(aspectRatio * (position1.x-(0.5*width))/ (0.5*width), (position1.y - (0.5*height)) / (0.5*height)); //starting point to draw from
	glVertex2f(aspectRatio * (position2.x - (0.5*width)) / (0.5*width), (position2.y - (0.5*height)) / (0.5*height)); //end point to draw too
	
	glEnd();                         // finished the line being drawn
}
