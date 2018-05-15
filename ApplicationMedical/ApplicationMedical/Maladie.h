// Maladie.h
#include <string>

#include "Empreinte.h"
#include "stdafx.h"

#ifndef Maladie_H
#define Maladie_H

using namespace std;

class Maladie
{
private:
	string nom;
	Empreinte empreinteMoyenne;
public:
	Maladie(string nom, Empreinte empreinteMoyenne);
	double presence(Empreinte empreinte);
};

#endif