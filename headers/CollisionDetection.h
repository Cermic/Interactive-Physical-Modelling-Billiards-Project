/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/
#pragma once

#include <glm\glm.hpp>
#include <iostream>
#include <string>
#include <float.h>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\ext.hpp>
#include "Segment.h"
#include "Circle.h"
#include "CollisionReaction.h"

using namespace std;
using namespace glm;


class CollisionDetection
{
public:
	void SegmentCircleCollisionTest(Segment & l1, Circle & c1);			// Defines the Segment Circle Collision Detection
	bool CircleCircleCollisionTest(Circle & c1, Circle & c2, float dt); // Defines the Circle Circle Collision Detection
	CollisionReaction cR;
	
};

