#include "stdafx.h"
#include "AttributDouble.h"

using namespace std;

AttributDouble::AttributDouble() {}

AttributDouble::AttributDouble(string nom, double data)
{
	cout << "Construction de l'attribut double : " << nom << ", " << data << endl;
	this->nom = nom;
	this->data = data;
}

AttributDouble::~AttributDouble()
{
	cout << "Construction d'un arrtibut double" << endl;
}

double AttributDouble::getData()
{
	return data;
}

double AttributDouble::distance(Attribut *attribut)
{
	AttributDouble *attributDouble = dynamic_cast<AttributDouble *>(attribut);
	cout << "Calcule de la distance de l'attribut double : " << attributDouble->nom << endl;
	double distance = 0;
	if (this->data - attributDouble->data > 0)
	{
		distance = (this->data - attributDouble->data) / attributDouble->data;
	}
	else if (attributDouble->data - this->data > 0)
	{
		distance = 2 * (attributDouble->data - this->data) / attributDouble->data;
	}

	if (distance > 1.0)
	{
		distance = 1.0;
	}
	return distance;
}