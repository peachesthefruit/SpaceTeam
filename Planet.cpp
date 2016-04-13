#include "Planet.h"

#define DEBUG 1 

// static vector of all planets
vector<Planet *> Planet::planets;

//constructor
Planet::Planet(string name, double m, double x, double y, double z) : name(name)
{
	mass = m;
	pos.set(x,y,z);
	planets.push_back(this);
}

//calculate the force
void Planet::calcForce()
{
	double G=6.67e-11;
	totalForce.clear();

	for (int i = 0; i < planets.size(); i++) {
		if (planets[i] != this) { // don't add force if it is with itself
			Tensor r = planets[i]->pos - pos;
			totalForce = totalForce + r*((G*mass*planets[i]->mass)/(r.getr()*r.getr()*r.getr()));
		}
	}

	accel = totalForce / mass;
}

//calculate acceleration based on force
Tensor Planet::calcAccel()
{
	this->accel = totalForce / mass;

	return (this->accel);
}

double Planet::getMass()
{
	return mass;
}

/*Tensor Planet::getPos()
{
	return pos;
}*/

double Planet::getx()
{
	return pos.getx();
}

double Planet::gety()
{
	return pos.gety();
}

double Planet::getz()
{
	return pos.getz();
}

//moves the planets according to the force
void Planet::update(double dt)
{
	// calculate force for each planet
	for (int i = 0; i < planets.size(); i++) {
		planets[i]->calcForce();

		if (DEBUG) cout << planets[i]->name << ":" << endl << planets[i]->pos << endl;
	}
	
	for (int i = 0; i < planets.size(); i++) {
		planets[i]->pos = planets[i]->pos + (planets[i]->vel*dt);
		planets[i]->vel = planets[i]->vel + (planets[i]->accel*dt);
	}
}
