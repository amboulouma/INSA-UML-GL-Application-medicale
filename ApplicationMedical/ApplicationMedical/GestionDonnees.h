// GestionDonnees.h
#include <string>
#include <list>
#include <unordered_map>

#include "Attribut.h"
#include "Maladie.h"

#ifndef GestionDonnees_H
#define GestionDonnees_H

using namespace std;

class GestionDonnees
{
	private:
		const string FICHIER_MALADIE;
		const string FICHIER_EMPREINTES;
		list<Maladie> listMaladie;
	
	public:
		unordered_map<string, double> analyse(Empreinte e);
		void analyse(list<Empreinte> listeEmpreintes);
		void associerMaladieEmpreinte(string maladie, Empreinte e);
		Empreinte trouverEmpreinteParID(int id);
};

#endif