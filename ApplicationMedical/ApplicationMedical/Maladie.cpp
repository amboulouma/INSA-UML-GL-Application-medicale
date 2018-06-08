#include "stdafx.h"
#include "Maladie.h"

Maladie::Maladie() {}

Maladie::Maladie(string nom, Empreinte empreinteMoyenne)
{
	this->nom = nom;
	this->empreinteMoyenne = empreinteMoyenne;
}

Maladie::~Maladie() {}

double Maladie::presence(Empreinte empreinte,vector<int> modele)
{
	return 1 - this->empreinteMoyenne.distance(empreinte,modele);
}

string Maladie::getNom()
{
	return nom;
}

Empreinte Maladie::getEmpreinteMoyenne()
{
	return empreinteMoyenne;
}

bool Maladie::operator==(Maladie& m)
{
	return (m.nom == this->nom);
}