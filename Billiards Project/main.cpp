/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include <glm\glm\glm.hpp>
#include <iostream>
#include <string>
#include <float.h>
#include <glm\glm\gtc\matrix_transform.hpp>
#include <glm\glm\gtc\type_ptr.hpp>
#include <glm\glm\ext.hpp>
#include "Segment.h"
#include "Circle.h"
#include "CollisionDetection.h"
#include <GL\glut.h>
#include "Timer.h"
#include "RunTime.h"

using namespace std;
using namespace glm;

float EPS = FLT_EPSILON;

RunTime* runTime; //setup pointer to a runtime instance for running the game

//setup timer and necessary properties
LowResTimer timer;
int refreshMillis = 16;
double oldTime = 0;

void display()
{
	runTime->Render();	// delegates drawing to the runtime class
}
void reshape(GLsizei width, GLsizei height)
{
	runTime->ReshapeWindow(width, height); //delegates reshaping to runtime class
}


void update(int value)
{
	runTime->Update(timer.getTime() - oldTime); //delegates updates tot he runtime class
	glutPostRedisplay();						// Post a paint request to activate display()
	glutTimerFunc(refreshMillis, update, 0);	// Subsequent timer call at milliseconds
	oldTime = timer.getTime(); //set oldtime for difference in time
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	runTime = new RunTime(); //new runtime 
	runTime->Load(); //delegate loading to runtime
	timer.startTimer(); //start timer
	glutDisplayFunc(display);		// Register callback handler for window re-paint
	glutReshapeFunc(reshape);		//handle window reshaping
	glutTimerFunc(0, update, 0);	// First timer call immediately
	glClearColor(0.0, 1.0, 0.0, 1.0); //clear screen
	glutMainLoop(); //continue main loop

	return 0;
}