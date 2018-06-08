#include "stdafx.h"
#include "AttributString.h"
#include <fstream>

AttributString::AttributString()
{
}

AttributString::AttributString(string nom, string data)
{
	this->nom = nom;
	this->data = data;
}

AttributString::~AttributString()
{
}

string AttributString::getData()
{
	return data;
}

double AttributString::distance(Attribut *attribut)
{
	AttributString* attributString = dynamic_cast<AttributString *>(attribut);
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Calcule de la distance de l'attribut string : " << attributString->nom << endl;
	os.close();

	double distance = 0.0;
	if (this->data != attributString->data)
		distance = 1.0;
	return distance;
}

bool AttributString::operator==(const Attribut & unAtt)
{
	const AttributString * attributString = dynamic_cast<const AttributString*>(&unAtt);
	if (attributString == NULL)
	{
		return false;
	}
	else
	{
		if (attributString->data == this->data)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}