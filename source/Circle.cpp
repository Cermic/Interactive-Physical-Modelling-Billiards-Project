/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "Circle.h"


void Circle::VelocityVerletSolver(float dt)
{
	//Refined Implementation
	position += (dt*velocity) + (0.5f*(dt*dt)*acceleration); //Step 1: Pos Update (NewPos=Pos+dt*velocity+0.5*(dt*dt)*acceleration
	velocity += (0.5f * dt * acceleration); //Step 2: Velocity Update (newVelocity=Veloctiy+0.5*dt*acceleration) - This is the update at the start of the frame.
	acceleration = forceAccum * invMass;// Step 3: Acceleration update (accelration = the force of the drag and gravity times the inverse mass of the billiard)
	velocity += (0.5f * dt * acceleration);//Step 4: Velocity Update (newVelocity=Veloctiy+0.5*dt*acceleration) - This is the update between frames.
}

void Circle::setAccelration(vec2 a)
{
	a = acceleration;
}

void Circle::setPosition(vec2 p)
{
	position = p;
}

void Circle::setVelocity(vec2 v)
{
	velocity = v;
}

void Circle::setXVelocity(float x)
{
	velocity.x = x;
}

void Circle::setYVelocity(float y)
{
	velocity.y = y;
}

vec2 Circle::setForceAccum()
{
	return vec2();
}

void Circle::clearAccumulator()
{
	forceAccum = vec2(0, 0);
}

void Circle::addForce(const vec2 & force)
{
	forceAccum += force;

}

void Circle::update(float dt)
{
	VelocityVerletSolver(dt);
	clearAccumulator();
	// updates the ball using the Verlet solver and then clears the force accumulated to stop a runaway force increase being applied
}

void Circle::draw(int width, int height)
{
	glLoadIdentity();				// Reset model-view matrix
	float aspectRatio = (width / (float)height);
	glTranslatef(aspectRatio * (position.x - (0.5f * width)) / (0.5f * width),
		(position.y - (0.5f * height)) / (0.5f * height), 0.0f);  // Translate to (xPos, yPos) coordinates

																  // Use triangular segments to form a circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(red, green, blue);								// Colours circle red
	glVertex2f(0.0f, 0.0f);										// Vector for the center of circle
	int numSegments = 100;
	float angle;
	for (int i = 0; i <= numSegments; i++) 
	{					// Last vertex same as first vertex
		angle = i * 2.0f * pi<float>() / numSegments;			// This makes a complete circle 360 degrees around the centre facotring in the number of segements
		glVertex2f(cos(angle) * (2.0f * radius / width)* aspectRatio,
			sin(angle) * (2.0f * radius / height));
	}
	glEnd();
}
