#include "Empreinte.h"

using namespace std;

Empreinte::Empreinte()
{
}

Empreinte::Empreinte(int id, vector<Attribut*> liste) : listeAttributs(liste)
{
	NoID = id;
}

Empreinte::~Empreinte()
{
	for (vector<Attribut*>::iterator it = listeAttributs.begin()
		; it != listeAttributs.end(); ++it)
	{
		delete *it;
	}
}

double Empreinte::distance(Empreinte e)
{
	double d = 0;
	vector<Attribut*> list1 = e.listeAttributs;
	for (unsigned int i = 0; i < modele.size(); i++) 
	{
		d = d + listeAttributs[i]->distance(*list1[i]);
	}
	return d;
}