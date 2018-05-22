#include "stdafx.h"
#include "AttributDouble.h"


using namespace std;

AttributDouble::AttributDouble() { }

AttributDouble::AttributDouble(string nom, double data) 
{
	this->nom = nom;
	this->data = data;
}

AttributDouble::~AttributDouble() { }

double AttributDouble::distance(Attribut * attribut)
{
	AttributDouble attributDouble = *dynamic_cast<AttributDouble*>(attribut);
	double distance = 0.0;
	if (this->data != attributDouble.data)
		distance = 1.0;
	return distance;
}