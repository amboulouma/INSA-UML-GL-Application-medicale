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
	protected:
		int NoID;
		vector<Attribut*> listeAttributs;
		static const string FICHIER_EMPREINTES;
		static const string FICHIER_METADONNEES;
		static vector<int> modele;
		static vector<string> nomAttribut;

	public:
		Empreinte();

		Empreinte(int id, vector<Attribut*> list);

		~Empreinte();

		double distance(Empreinte e);
		void sauvegarderEmpreinte();

		int getID();

		vector<Attribut*> getListeAttributs();

};

#endif
