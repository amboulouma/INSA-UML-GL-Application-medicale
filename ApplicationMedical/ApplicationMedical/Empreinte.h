#pragma once
// Empreinte.h
#include <string>
#include <list>
#include <vector>
#include "Attribut.h"
#include "AttributString.h"
#include "AttributDouble.h"
#include "stdafx.h"


#ifndef Empreinte_H
#define Empreinte_H

using namespace std;

class Empreinte
{
	friend class GestionDonnees;
	friend class GestionFichier;
	protected:
		int NoID;
		vector<Attribut*> listeAttributs;
		static const string FICHIER_EMPREINTES;
		static const string FICHIER_METADONNEES;

	public:
		Empreinte();

		Empreinte(int id, vector<Attribut*> list);

		~Empreinte();

		double distance(Empreinte e,vector<int> modele);

		int getID() const;

		vector<Attribut*> getListeAttributs();

		bool operator==(const Empreinte &) const;

};

#endif
