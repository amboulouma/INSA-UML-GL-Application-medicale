#include "stdafx.h"
#include "Maladie.h"

Maladie::Maladie()
{
	cout << "Construction d'une maladie" << endl;
}

Maladie::Maladie(string nom, Empreinte empreinteMoyenne)
{
	cout << "Construction de la maladie : " << nom << ", " << empreinteMoyenne->NoID << endl;
	this->nom = nom;
	this->empreinteMoyenne = empreinteMoyenne;
}

Maladie::~Maladie()
{
	cout << "Destruction d'une maladie" << endl;
}

double Maladie::presence(Empreinte empreinte)
{
	cout << "Calcule de la présence de l'empreinte : " << empreinte->NoID << endl;
	return 1 - this->empreinteMoyenne.distance(empreinte);
}

string Maladie::getNom()
{
	return nom;
}

Empreinte Maladie::getEmpreinteMoyenne()
{
	return empreinteMoyenne;
}