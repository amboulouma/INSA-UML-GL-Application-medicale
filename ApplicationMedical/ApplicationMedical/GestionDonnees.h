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
	vector<string> nomAttribut;
	vector<int> modele;


  public:
	GestionDonnees();

	~GestionDonnees();
	
	void defModele();
	void calculerMaladies ();
	unordered_map<string,double> analyse(const Empreinte & e);
	void analyse(const list<Empreinte>& listeEmpreintes);
	void associerMaladieEmpreinte(string maladie, Empreinte e);
	Empreinte trouverEmpreinteParID(int id);
	void getMaladies(list<Maladie> & maladies);
	void getModele(vector<int> & schema);


	vector<string> splitLine(string line, char separator);
};

#endif
