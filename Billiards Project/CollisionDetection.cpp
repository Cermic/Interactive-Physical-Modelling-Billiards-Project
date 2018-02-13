/*

Name: Jack D Smith, Rhys Murray

Student ID: B00308927, B00308897

I declare that the following code was produced by (Jack D Smith & Rhys Murray) as a group assignment for the IPM module and that this is our own work.

I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.

*/

#include "CollisionDetection.h"


void CollisionDetection::SegmentCircleCollisionTest(Segment & s1, Circle & c1) // Takes in the two Circles
{
	
	vec2 r = s1.getPosition1() - c1.getPosition(); // vector r is the distance between the segment and circle

	vec2 projection = dot(r, s1.getNormal()) * s1.getNormal(); 
	// projection vector is given the normalised dot product of the normal and r. 
	// This works out a vector at 90 degrees to the segment from the circle.
	vec2 projectedPoint;
	
	projectedPoint = c1.getPosition() + projection;
	// projected point is the centre of the circle plus the projection. 
	// So this makes it the point on the line the circle is above when the projected point is recorded
	
	

	float distance1 = glm::distance(s1.getPosition1(), projectedPoint);
	//gets the distance between the first point on the segment and the projected point - d1
	float distance2 = glm::distance(s1.getPosition2(), projectedPoint);
	//gets the distance between the second point on the segment is and the projected point - d2
	float lengthOfSeg = glm::distance(s1.getPosition1(), s1.getPosition2()); 
	// lengthOfSeg = the length of the segment - d

	/////CIRCLE VELOCITY RESOLUTION
	vec2 velPerp = dot(c1.getVelocity(),s1.getNormal()) * s1.getNormal(); 
	// velPerp gets the Circles velocity perpendicular to the segment
	vec2 velParallel = c1.getVelocity() - velPerp; 
	// velParallel get the Circle's velocity parrallel to the segement

	/////

	/* For Collision Detection
	   1st IF 
	   The first and second condition stops the circle colliding with the line after its defined limit. 
	   The third condition compares the distance the Circle is from the line and it's radius.
		If these conditions are satisfied then a text output is given and the velocity of the circle
		is set by the Circle's negative perpendicular velocity to the segment and positive parallel velocity
		thus directing in the opposite angle that it hit the segment at while maintaining it's "forward" velocity
	   
	   2nd & 3rd IF
	   They perform the same first 2 checks as the first. The purpose of these is to account for a bigger system
	   where there may be objects made up of segements that can be hit from any side. They apply the same code, they just
	   check whether the circles will hit the other side of the segment.
	   
	   */
	if ((distance1 < lengthOfSeg) && (distance2 < lengthOfSeg)
		&& (-dot(r, s1.getNormal()) < c1.getRadius()))
	{
		cout << "COLLISION SEG-CIRCLE "<< distance1 <<" < "<< lengthOfSeg<< " && " << distance2 << " < " << lengthOfSeg << endl;//debugging output

		c1.setVelocity(-velPerp + velParallel);

	}
	else if ((distance1 > lengthOfSeg) && (distance2 < c1.getRadius()))
	{
		cout << "COLLISION SEG-CIRCLE " << distance1 << " > " << lengthOfSeg << " && " << distance2 << " < " << c1.getRadius() << endl;//debugging output

		c1.setVelocity(-velPerp + velParallel);

	}else if ((distance2 > lengthOfSeg) && (distance1 < c1.getRadius()))
	{
		cout << "COLLISION SEG-CIRCLE " << distance2 << " >LENGTH && " << distance1 << " < " << c1.getRadius() << endl;//debugging output

		c1.setVelocity(-velPerp + velParallel);

	}
	
};

bool CollisionDetection::CircleCircleCollisionTest(Circle & c1, Circle & c2, float dt)// Takes in two Circles and delta t, the time increment
{
	bool output = false;
	float distanceBetweenCircles = glm::distance(c1.getPosition(), c2.getPosition());
	// Works out the distance between the circles using their centres
	float penetration = distanceBetweenCircles - (c1.getRadius() + c2.getRadius());
	// Works out the how much the circles overlapped using their ditance between each other and the combines radii

	/*The Circles collide when their radii is <= the distance between their centres 
	  If the Circles collide then text is output to show the user
	  The circles are then passed into a vector
	  Sets the contact normal to the point of collision
	  Sets the penetration to how much the circles overlapped
	  The Restitution for the collision is passed in
	  Resolves the velocity and interpenetration since the last time increment
	  
	  else there is no output from the algorithm
	  */
	if (distanceBetweenCircles < (c1.getRadius() + c2.getRadius()))
	{
		cout << "2 Collisions occuring between Circles" << endl;
		cR.setObjects(vector<Circle*> { &c1, &c2 });
		cR.setContactNormal(glm::normalize(c1.getPosition() - c2.getPosition()));
		cR.setPenetration(penetration);
		cR.setRestiution(0.6);
		cR.Resolve(dt);
	}
	else if (distanceBetweenCircles == (c1.getRadius() + c2.getRadius()))
	{
		cout << "1 Collisions occuring between Circles" << endl;
		cR.setObjects(vector<Circle*> { &c1, &c2 });
		cR.setContactNormal(glm::normalize(c1.getPosition() - c2.getPosition()));
		cR.setPenetration(penetration);
		cR.setRestiution(0.6);
		cR.Resolve(dt);
	}
	else
	{
		output = false;
	}

	return output;

};