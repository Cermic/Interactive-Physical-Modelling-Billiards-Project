/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#include "RunTime.h"


using namespace std;

void wait(long seconds)
{
	seconds = seconds * 1000;
	Sleep(seconds);
}

void RunTime::Load()
{
	//initialise all game objects

	window = new GameWindow("Physics motion test", 640, 480, 50, 50);
	forceReg = new ForceRegistry();
	//gravity = new Gravity(vec3(0.5f, 0.0f, 0.0f));
	drag = new Drag(0.4f, 0.02f);
	
	//take in initial values for the "cue ball" velocity and all billiards masses
	/*
	cout << "Insert a mass in kg" << endl;
	cin >> massInput;

	cout << "Insert velocity X" << endl;
	cin >> velocityInput.x;

	cout << "Insert velocity Y" << endl;
	cin >> velocityInput.y;
	*/
	positionInput = vec2(100.0, 240.0);
	massInput = 5;
	velocityInput.x = 1000; // Straight shot
	velocityInput.y = 0;

	//positionInput = vec2(350.0, 120.0);
	//massInput = 5;
	//velocityInput.x = 500; // Right shot
	//velocityInput.y = 1000;

	//positionInput = vec2(400.0, 400.0);
	//massInput = 5;
	//velocityInput.x = 0; // Left shot 
	//velocityInput.y = -1000;

	//initialise billiards

	billiards[0] = new Circle(positionInput, 10.0f, velocityInput, vec2(0.0, 0.0), (1/(float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 1.0f), 0); //cue ball

	billiards[1] = new Circle(vec2(400.0, 240.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0, 1.0f, 0.0f), 1); //yellow

	billiards[2] = new Circle(vec2(415.0, 255.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput),  vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 2); //yellow
	billiards[3] = new Circle(vec2(415.0, 225.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0, 0.0f, 0.0f), 3); //red

	billiards[4] = new Circle(vec2(430.0, 270.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 4); //yellow
	billiards[5] = new Circle(vec2(430.0, 240.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(0.0f, 0.0f, 0.0f), 5); //black
	billiards[6] = new Circle(vec2(430.0, 210.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 6); //yellow

	billiards[7] = new Circle(vec2(445.0, 285.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 7); //yellow
	billiards[8] = new Circle(vec2(445.0, 255.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0, 0.0f, 0.0f), 8); //red
	billiards[9] = new Circle(vec2(445.0, 225.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 9); //yellow
	billiards[10] = new Circle(vec2(445.0, 195.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0, 0.0f, 0.0f), 10); //red

	billiards[11] = new Circle(vec2(460.0, 300.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 11); //yellow
	billiards[12] = new Circle(vec2(460.0, 270.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0, 0.0f, 0.0f), 12); //red
	billiards[13] = new Circle(vec2(460.0, 240.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 13); //yellow
	billiards[14] = new Circle(vec2(460.0, 210.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0, 0.0f, 0.0f), 14); //red
	billiards[15] = new Circle(vec2(460.0, 180.0), 10.0f, vec2(0.0, 0.0), vec2(0.0, 0.0), (1 / (float)massInput), vec2(0, 0), vec3(1.0f, 1.0f, 0.0f), 15); //yellow
	
	for (int count = 0; count < 16; count++) //add drag force to each billiard
	{
		forceReg->add(billiards[count], drag);
		//forceReg->add(billiards[count], gravity);
	}

	boundaries[0] = new Segment(vec2(0.0f,470.0f), vec2(640, 470.0f), vec2 (0,-1),0); // top boundary
	boundaries[1] = new Segment(vec2(0.0f, 0.0f), vec2(640.0f, 0.0f), vec2(0, 1) ,1); // bottom boundary
	boundaries[2] = new Segment(vec2(0.0, 0.0f), vec2(0.0f, 480.0f), vec2(1, 0) ,2); // left boundary
	boundaries[3] = new Segment(vec2(630.0f, 0.0f), vec2(630.0f, 480.0f), vec2(-1, 0) ,3); // right boundary

	wait(3);
}

void RunTime::ReshapeWindow(int width, int height)
{
	window->Reshape(width, height); //delegate handling of reshape to gamewindow class
}

void RunTime::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);	// Clear the color buffer
	
	glMatrixMode(GL_MODELVIEW);		// To operate on the model-view matrix

	for (int i = 0; i < 16;i++) //for loop to draw billiards
	{
		billiards[i]->draw(640, 480);
	}

	for (int i = 0; i < 4;i++) //for loop to draw each table boundary 
	{
		boundaries[i]->draw(640, 480);
	}
	
	glutSwapBuffers(); //swap buffers
}



void RunTime::Update(float dt)
{
	

	forceReg->updateForces(dt); //update all registered forces

	//ball updates using verlet solver
	for (int i = 0; i < 16; i++)
	{
		billiards[i]->update(dt);
	}

	//circle-circle collision checking
	for (int i = 0; i <16; i++)//i=ball count
	{
		for (int j = 0; j < 16; j++)//j=ball count
		{
			if (billiards[i]->getId() != billiards[j]->getId())  //prevent ball checking against itsself
			{
				if (col.CircleCircleCollisionTest(*billiards[i], *billiards[j], dt)) //handles collisions between billiards
				{
					cout << "Collision" << endl; //debugging output
				}			
			}
		}
	}

	//circle-boundary collision checking
	for (int i = 0; i <4; i++) //i=boundary count
	{
		for (int j = 0; j < 16; j++)//j=ball count
		{
			col.SegmentCircleCollisionTest(*boundaries[i], *billiards[j]); //handle collisions between billiards/boundaries
		}
	}
	int movementCounter = 0;
	// Velocity management
	for (int i = 0; i < 16; i++)//i=ball count
	{
		if (billiards[i]->getVelocity().x < 10)
		{
			billiards[i]->setXVelocity(0.0f);
		}

		if (billiards[i]->getVelocity().y < 10)
		{
			billiards[i]->setYVelocity(0.0f);
		}

		if (billiards[i]->getVelocity().x == 0.0 && billiards[i]->getVelocity().y == 0.0)
		{
			movementCounter++;
			if (movementCounter == 16)
			{
				cout << "Insert velocity X" << endl;
				cin >> velocityInput.x;

				cout << "Insert velocity Y" << endl;
				cin >> velocityInput.y;

				movementCounter = 0;
			}
		}
	}
	
}



