#pragma once
// Empreinte.h
#include <string>
#include <list>
#include "Attribut.h"
#ifndef Empreinte_H
#define Empreinte_H

using namespace std;

class Empreinte
{
	protected:
		int NoID;
		list<Attribut*> listeAttributs;
		static const string FICHIER_EMPREINTES;
		static const string FICHIER_METADONNEES;
		static list<int> modele;

	public:
		double Distance(Empreinte e);
		void SauvegarderEmpreinte();
};

#endif
