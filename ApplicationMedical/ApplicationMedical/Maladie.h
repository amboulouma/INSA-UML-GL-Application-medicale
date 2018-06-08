#include "stdafx.h"

// Maladie.h
#include <string>

#include "Empreinte.h"

#ifndef Maladie_H
#define Maladie_H

using namespace std;

class Maladie
{
	friend class GestionDonnees;

private:
	string nom;
	Empreinte empreinteMoyenne;

public:
	Maladie();

	Maladie(string nom, Empreinte empreinteMoyenne);

	~Maladie();

	double presence(Empreinte empreinte);

	string getNom();

	Empreinte getEmpreinteMoyenne();
};

#endif