#include "stdafx.h"
#include "Attribut.h"
#include "AttributString.h"
#include "AttributDouble.h"
#include "Empreinte.h"
#include "GestionDonnees.h"
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
	vector<Attribut *> listAttributs;
	Attribut *attribut1 = new AttributString("A1", "False");
	listAttributs.push_back(attribut1);
	Attribut *attribut2 = new AttributDouble("A2", 7.8);
	listAttributs.push_back(attribut2);
	Attribut *attribut3 = new AttributDouble("A3", 80);
	listAttributs.push_back(attribut3);
	Attribut *attribut4 = new AttributDouble("A4", 7.628);
	listAttributs.push_back(attribut4);
	Attribut *attribut5 = new AttributDouble("AZ51", 68.5);
	listAttributs.push_back(attribut5);

	Empreinte empreinte(1, listAttributs);

	GestionDonnees gestionDonnees;

	unordered_map<string, double> ressource = gestionDonnees.analyse(empreinte);
	gestionDonnees.associerMaladieEmpreinte("Maladie1", empreinte);

	Empreinte empreinte1 = gestionDonnees.trouverEmpreinteParID(2);

	return 0;
}
