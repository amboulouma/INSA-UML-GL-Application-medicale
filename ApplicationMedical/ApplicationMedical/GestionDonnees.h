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
	string FICHIER_MALADIE = "Maladies.txt";
	string FICHIER_EMPREINTES = "Empreintes.txt";
	
	vector<string> nomAttribut;
	vector<int> modele;

  public:

list<Maladie> listMaladie;
	GestionDonnees();

	~GestionDonnees();

	void defModele();
	void calculerMaladies();
	void analyse(const Empreinte &Empreinte);
	void analyse(list<Empreinte> listeEmpreintes);
	void associerMaladieEmpreinte(string maladie, Empreinte e);
	Empreinte trouverEmpreinteParID(int id);
	void getMaladies(list<Maladie> & maladies);
	void getModele(vector<int> & schema);
	void getNomsAttributs(vector<string> & noms);

	string getFichierMaladie();
	string getFichierEmpreintes();

	void setFichierMaladie(const string & fichierMaladie);
	void setFichierEmpreintes(const string & fichierEmpreintes);
	void affichageMaladies();

	vector<string>splitLine(string line, char separator);
};

#endif
