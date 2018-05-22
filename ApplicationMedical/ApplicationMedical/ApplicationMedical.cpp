// ApplicationMedical.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Attribut.h"
#include "AttributString.h"
#include "AttributDouble.h"
#include "Empreinte.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<Attribut*> list1;
	Attribut * a1 = new AttributString("A1", "true");
	list1.push_back(a1);
	Attribut * a2 = new AttributDouble("A2", 2.12);
	list1.push_back(a2);
	Attribut * a3 = new AttributDouble("A3", 13);
	list1.push_back(a3);
	Attribut * a4 = new AttributDouble("A4", 3.156);
	list1.push_back(a4);
	Attribut * a5 = new AttributDouble("A5", 2367);
	list1.push_back(a5);
	Empreinte e(1, list1);
	cout << "lol" << endl;

	vector<Attribut*> list2;
	Attribut * b1 = new AttributString("A1", "false");
	list2.push_back(b1);
	Attribut * b2 = new AttributDouble("A2", 1.1);
	list2.push_back(b2);
	Attribut * b3 = new AttributDouble("A3", 14.3);
	list2.push_back(b3);
	Attribut * b4 = new AttributDouble("A4", 13.2);
	list2.push_back(b4);
	Attribut * b5 = new AttributDouble("A5", 2367);
	list2.push_back(b5);
	Empreinte e2(2, list2);
	double d = e2.distance(e);
	cout << d << endl;

    return 0;

}

