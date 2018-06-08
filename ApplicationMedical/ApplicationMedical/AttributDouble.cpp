#include "stdafx.h"
#include "AttributDouble.h"

using namespace std;

AttributDouble::AttributDouble()
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Construction d'un attribut double" << endl;
	os.close();
}

AttributDouble::AttributDouble(string nom, double data)
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Construction de l'attribut double : " << nom << ", " << data << endl;
	os.close();
	this->nom = nom;
	this->data = data;
}

AttributDouble::~AttributDouble()
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Destruction d'un attribut double" << endl;
	os.close();
}

double AttributDouble::getData()
{
	return data;
}

double AttributDouble::distance(Attribut *attribut)
{
	AttributDouble *attributDouble = dynamic_cast<AttributDouble *>(attribut);
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Calcule de la distance de l'attribut double : " << attributDouble->nom << endl;
	os.close();
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