#include "stdafx.h"
#include "AttributString.h"

AttributString::AttributString() { }

AttributString::AttributString(string nom, string data) 
{
	this->nom = nom;
	this->data = data;
}

AttributString::~AttributString() { }

double AttributString::distance(AttributString attributString)
{
	double distance = 0.0;
	if (this->data != attributString.data)
		distance = 1.0;
	return distance;
}