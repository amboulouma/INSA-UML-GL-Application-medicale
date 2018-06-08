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

double AttributDouble::getData()
{
	return data;
}

double AttributDouble::distance(Attribut * attribut)
{
	AttributDouble* ad = dynamic_cast<AttributDouble*>(attribut);
	double distance = 0;
	if (this->data-ad->data > 0)
	{
		distance = (this->data - ad->data) / ad->data;
	}
	else if (ad->data - this->data > 0)
	{
		distance = 2 * (ad->data - this->data) / ad->data;
	}

	if (distance > 1.0)
	{
		distance = 1.0;
	}
	return distance;
}

bool AttributDouble::operator==(const Attribut & unAtt)
{
	const AttributDouble * attributDouble = dynamic_cast<const AttributDouble*>(&unAtt);
	if (attributDouble == NULL)
	{
		return false;
	}
	else
	{
		if (attributDouble->data - this->data < 0.000001
			&& attributDouble->data - this->data > -0.000001)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}