/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once
#include <iostream>
#include <GL\glut.h>
#include "Circle.h"
#include "CollisionDetection.h"
#include "Segment.h"
#include <vector>
#include <string>
#include "GameWindow.h"
#include "ForceGenerator.h"
#include "ForceRegistry.h"
#include "Gravity.h"
#include "Drag.h"

using namespace std;

class RunTime {

public : 
	void Load(); //load method for loading all game objects
	void ReshapeWindow(int weigth, int height); //reshape function to allow window reshaping
	void Render(); //render method for drawing game objects
	void Update(float dt); //update method for carrying out necessary

	RunTime() {};
	virtual ~RunTime()
	{
		if (billiards != nullptr) delete billiards;
		if (boundaries != nullptr) delete boundaries;
	}
private:
	Circle* billiards[16]; //create all circle object pointers for billiards
	Segment* boundaries[4]; //create all segment object pointers for table boundaries
	CollisionDetection col; //collision detection object to allow collision checking
	GameWindow* window; //game window pointer
	ForceRegistry* forceReg; //forceRegistery pointer for registering necessary forces 
	Gravity* gravity; //gravity pointer for delcaring gravity in the scene
	Drag* drag; //drag pointer for declaring how drag operates in the scene
	float massInput; //float for taking dynamic mass for billiards
	vec2 velocityInput; //vec2 for declaring initial velocity of the cue ball
	vec2 positionInput;
};
