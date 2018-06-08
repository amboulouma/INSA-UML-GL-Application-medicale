// GestionFichier.h
#include <string>
#include <unordered_map>
#include <map>

#include "stdafx.h"

#include "Empreinte.h"

#ifndef GestionFichier_H
#define GestionFichier_H

using namespace std;

class GestionFichier
{
  private:
	string DEF_EMPREINTE = "Metadonnees.txt";
	string BD_MALADIE = "Maladies.txt";
	string ANALYSE_EMPREINTE = "Empreintes.txt";

  public:
	GestionFichier();

	~GestionFichier();

	void ajouterDansBD(Empreinte &, string nomMaladie, vector<int> &modele);

	void modeleEmpreinte(vector<string> &nomAttribut, vector<int> &modele);
	void lireBD(unordered_map<string, Empreinte> &, vector<int> &modele);
	void lireEmpreinte(vector<Empreinte> &, vector<int> modele, vector<string> nomAttribut);

	vector<string> splitLine(string line, char separator);

	string getDefEmpreinte();
	string getBdMaladie();
	string getAnalyseEmpreinte();

	void setDefEmpreinte(const string &defEmpreinte);
	void setBdMaladie(const string &bdMaladie);
	void setAnalyseEmpreinte(const string &analyseEmpreinte);

	void affichageEmpreintes();
	void affichageMaladies();
};

#endif
