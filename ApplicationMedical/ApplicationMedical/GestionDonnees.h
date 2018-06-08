// GestionDonnees.h
#include <string>
#include <list>
#include <unordered_map>

#include "stdafx.h"
#include "Attribut.h"
#include "Maladie.h"

#ifndef GestionDonnees_H
#define GestionDonnees_H

using namespace std;

class GestionDonnees
{
private:
	const string FICHIER_MALADIE = "Maladies.txt";
	const string FICHIER_EMPREINTES = "Empreintes.txt";
	list<Maladie> listMaladie;

public:
	GestionDonnees();

	~GestionDonnees();

	void genererListeMaladie();
	unordered_map<string, double> analyse(Empreinte e);
	void analyse(list<Empreinte> listeEmpreintes);
	void associerMaladieEmpreinte(string maladie, Empreinte e);
	vector<string> splitLine(string line, char separator);
	Empreinte trouverEmpreinteParID(int id);
};

#endif