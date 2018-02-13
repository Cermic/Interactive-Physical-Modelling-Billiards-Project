//Based on code provided in lecture 12 of IPM module, provided by Marco Gilardi.
//Code modified by Jack D. Smith and Rhys Murray (B00308927 & B00308897)
//Changes made;
//-Changed type of object in forceRegistration struct to circle from gameObject
//-Changed type of object passed into add and remove methods from GameObject to Circle object
//-Properties within method now take from circle objects instead of game objects

#include "ForceRegistry.h"

void ForceRegistry::add(Circle * circle, ForceGenerator * fg)
{
	ForceRegistration fr; //delcares a force registery
	fr.fg = fg; //sets the registrys force to be the passed in force
	fr.circle = circle; //sets the registrys object to be the passed in object
	registrations.push_back(fr); //pushs the registration onto the list of active registered forces
}

void ForceRegistry::remove(Circle * circle, ForceGenerator * fg)
{
	for (vector<ForceRegistration>::iterator it = registrations.begin(); it < registrations.end(); it++) //for the list of active forces
	{
		if (it->circle == circle) //if the object for the force is the passed in object
		{
			registrations.erase(it); //remove that registered force
			break;
		}
	}
}

void ForceRegistry::updateForces(float dt)
{
	for (vector<ForceRegistration>::iterator it = registrations.begin(); it < registrations.end(); ++it)
	{
		it->fg->updateForce(it->circle, dt); //updates all forces in the list of registered forces
	}
}
