//Based on code provided in lecture 13 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object passed into class from GameObjects to Circle objects
//-Properties within methods now take from circle objects instead of game objects

#include "CollisionReaction.h"

float CollisionReaction::ResolveRestingContact(float dt)
{
	vec2 accCausedVel = obj[0]->getAcceleration(); //get first objects acceleration
	float result;
	if (obj[1]) //if second object exists
	{
		accCausedVel += obj[1]->getAcceleration(); //add second objects acceleartion to accCausedVel
	}
	float accCausedSepVel = glm::dot(accCausedVel, contactNormal)*dt;  //calculates a seperating velocity from acceleartion of the two objects and their collision point over the time increment between checks
	if (accCausedSepVel < 0)
	{
		result = restitution*accCausedSepVel;  //if there is a resultant velocity from these calculations, return that velocity multipled by the coefficent of restiution to take restitution into account
	}
	else
	{
		result = 0;  //otherwise return 0;
	}
	return result;
}

void CollisionReaction::ResolveVelocity(float dt)
{
	float separatingVelocity = ComputeSeparatingVelocity(); //calculate the sepearting velocity beween the two objects in relation to contact normal
	if (separatingVelocity > 0)
	{
		return; //catch to ensure velocity taking into accout restitution and resting contacts is not negative
	}
	float newSepVel = -separatingVelocity * (1 + restitution) + ResolveRestingContact(dt); //calculates the actual seperating velocity, taking restitution and if one of the objects is at rest into account
	if (newSepVel < 0)
	{
		newSepVel = 0; //catch to prevent incorrect impulse calculation
	}
	float totalInvMass = obj[0]->getInverseMass(); //sets initial total inverse mass to the first objects inverse mass
	if (obj[1])
	{
		totalInvMass += obj[1]->getInverseMass(); //adds second objects inverse mass to the total if the second object exists
	}
	if (totalInvMass < 0)
	{
		return; //catch to prevent incorrect impulse calculation
	}
	float impulseLength = newSepVel / totalInvMass;  //magnitude of impulse force = seperating velocity / total inverse mass of objects
	vec2 impulse = impulseLength * contactNormal; //resultant impulse force = magnitude of impulse * contact normal

	obj[0]->setVelocity(obj[0]->getVelocity() + impulse * obj[0]->getInverseMass()); //set object[0]s new velocity to its initial velocity + resultant impulse force/inverse mass

	if (obj[1]) //if second object exists
	{
		obj[1]->setVelocity(obj[1]->getVelocity() - impulse * obj[1]->getInverseMass()); //set object[1]s new velocity to its initial velocity + resultant impulse force/inverse mass
	}
}

void CollisionReaction::ResolveInterpenetration(float dt)
{
	if (penetration <= 0) return; //if no penetration, no need to carry out further calculation

	float totalInvMass = obj[0]->getInverseMass(); //sets initial total inverse mass to the first objects inverse mass
	if (obj[1]) totalInvMass += obj[1]->getInverseMass(); //adds second objects inverse mass to the total if the second object exists
	if (totalInvMass <= 0) return; //catch to prevent incorrect movement calculation
	vec2 movePerUnitMass = contactNormal * (-penetration / totalInvMass);  //movement in the direction of the contact normal by the total pentration amount taking objects inverse mass into acocunt

	obj[0]->setPosition(obj[0]->getPosition() +
		movePerUnitMass * obj[0]->getInverseMass()); //move the first object by the necessary amount
	if (obj[1])
		obj[1]->setPosition(obj[1]->getPosition() +
			movePerUnitMass * obj[1]->getInverseMass());  //move the second object by the necessary amount if it exists

}


//setters for necessary properties

void CollisionReaction::setObjects(vector<Circle*>& objects)
{
	obj = objects;
}

void CollisionReaction::setPenetration(float pen)
{
	penetration = pen;
}

void CollisionReaction::setRestiution(float res)
{
	restitution = res;
}

void CollisionReaction::setContactNormal(vec2 normal)
{
	contactNormal = normal;
}

//resolve function to contain both private resolve functions, easier to call elsewhere
void CollisionReaction::Resolve(float dt)
{
	ResolveVelocity(dt);
	ResolveInterpenetration(dt);

}

float CollisionReaction::ComputeSeparatingVelocity() const
{
	vec2 relVelocity = obj[0]->getVelocity(); //set initial resulting velocity to the first objects velocity
	if (obj[1]) //if second object exists
	{
		relVelocity -= obj[1]->getVelocity(); //take the second objects velocity away from the first
	}
	return glm::dot(relVelocity, contactNormal); //return the resultant velocity in relation to the contact normal

}