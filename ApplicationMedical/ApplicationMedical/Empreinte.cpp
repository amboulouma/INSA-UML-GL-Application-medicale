#include "Empreinte.h"

using namespace std;

Empreinte::Empreinte()
{
}

Empreinte::Empreinte(int id, list<Attribut*> liste) : listeAttributs(liste)
{
	NoID = id;
}

Empreinte::~Empreinte()
{
	for (list<Attribut*>::iterator it = listeAttributs.begin()
		; it != listeAttributs.end(); ++it)
	{
		delete *it;
	}
}

double Empreinte::distance(Empreinte e)
{
	double d;
	
}