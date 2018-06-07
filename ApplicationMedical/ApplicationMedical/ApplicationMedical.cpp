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
	/*
	vector<Attribut*> list1;
	Attribut * a1 = new AttributString("A1", "true");
	list1.push_back(a1);
	Attribut * a2 = new AttributDouble("A2", 2.12);
	list1.push_back(a2);
	Attribut * a3 = new AttributDouble("A3", 0);
	list1.push_back(a3);
	Attribut * a4 = new AttributDouble("A4", 0);
	list1.push_back(a4);
	Attribut * a5 = new AttributDouble("AZ51", 0);
	list1.push_back(a5);
	Empreinte e(1, list1);
	e.sauvegarderEmpreinte();
	cout << "lol" << endl;

	vector<Attribut*> list2;
	Attribut * b1 = new AttributString("A1", "false");
	list2.push_back(b1);
	Attribut * b2 = new AttributDouble("A2", 1.1);
	list2.push_back(b2);
	Attribut * b3 = new AttributDouble("A3", 0);
	list2.push_back(b3);
	Attribut * b4 = new AttributDouble("A4", 0);
	list2.push_back(b4);
	Attribut * b5 = new AttributDouble("A5", 0);
	list2.push_back(b5);
	Empreinte e2(2, list2);
	double d = e2.distance(e);
	e2.sauvegarderEmpreinte();
	cout << d << endl;


	vector<int> test;
	test.push_back(10);
	test.push_back(15);
	test[1] = 9;
	cout << test[1] << endl;

	string s = "aaa,bbb";
	cout << s.substr(0, s.find(','));
	*/


	vector<Attribut*> list1;
	Attribut * a1 = new AttributString("A1", "True");
	list1.push_back(a1);
	Attribut * a2 = new AttributDouble("A2", 7.06);
	list1.push_back(a2);
	Attribut * a3 = new AttributDouble("A3", 79);
	list1.push_back(a3);
	Attribut * a4 = new AttributDouble("A4", 7.628);
	list1.push_back(a4);
	Attribut * a5 = new AttributDouble("AZ51", 623.5);
	list1.push_back(a5);
	Empreinte e(1, list1);

	GestionDonnees gd;

	unordered_map<string, double> res = gd.analyse(e);
	gd.associerMaladieEmpreinte("Maladie1", e);
	return 0;
}

