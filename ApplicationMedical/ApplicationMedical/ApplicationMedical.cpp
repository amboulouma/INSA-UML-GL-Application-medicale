// ApplicationMedical.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Attribut.h"
#include "AttributString.h"
#include "AttributDouble.h"
#include "Empreinte.h"
#include <vector>

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
	Attribut * a5 = new AttributDouble("A5", 1236);
	list1.push_back(a5);
	Empreinte e(1, list1);
    return 0;
}

