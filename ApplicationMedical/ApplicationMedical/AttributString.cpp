#include "stdafx.h"
#include "AttributString.h"

AttributString::AttributString()
{
	cout << "Construction d'un attribut string" << endl;
}

AttributString::AttributString(string nom, string data)
{
	cout << "Construction de l'attribut string : " << nom << ", " << data << endl;
	this->nom = nom;
	this->data = data;
}

AttributString::~AttributString()
{
	cout << "Destruction d'un attribut string" << endl;
}

string AttributString::getData()
{
	return data;
}

double AttributString::distance(Attribut *attribut)
{
	AttributString attributString = *dynamic_cast<AttributString *>(attribut);
	cout << "Calcule de la distance de l'attribut double : " << attributString->nom << endl;
	double distance = 0.0;
	if (this->data != attributString.data)
		distance = 1.0;
	return distance;
}