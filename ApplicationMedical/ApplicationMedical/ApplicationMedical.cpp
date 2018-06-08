// ApplicationMedical.cpp : définit le point d'entrée pour l'application console.
//

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
	vector<Attribut*> list1;
	Attribut * a1 = new AttributString("A1", "False");
	list1.push_back(a1);
	Attribut * a2 = new AttributDouble("A2", 7.8);
	list1.push_back(a2);
	Attribut * a3 = new AttributDouble("A3", 80);
	list1.push_back(a3);
	Attribut * a4 = new AttributDouble("A4", 7.628);
	list1.push_back(a4);
	Attribut * a5 = new AttributDouble("AZ51", 68.5);
	list1.push_back(a5);
	Empreinte e(1, list1);

	GestionDonnees gd;

	unordered_map<string, double> res = gd.analyse(e);
	gd.associerMaladieEmpreinte("Maladie1", e);

	Empreinte e1 = gd.trouverEmpreinteParID(2);

	return 0;
}

