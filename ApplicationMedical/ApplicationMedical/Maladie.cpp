#include "stdafx.h"
#include "Maladie.h"

Maladie::Maladie()
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Construction d'une maladie" << endl;
	os.close();
}

Maladie::Maladie(string nom, Empreinte empreinteMoyenne)
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Construction de la maladie : " << nom << ", " << empreinteMoyenne->NoID << endl;
	os.close();
	this->nom = nom;
	this->empreinteMoyenne = empreinteMoyenne;
}

Maladie::~Maladie()
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Destruction d'une maladie" << endl;
	os.close();
}

double Maladie::presence(Empreinte empreinte)
{
	ofstream os;
	os.open(FICHIER_LOGS, ofstream::out | ofstream::app);
	os << "Calcule de la présence de l'empreinte : " << empreinte->NoID << endl;
	os.close();
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