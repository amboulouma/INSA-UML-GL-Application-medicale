#include "Empreinte.h"
#include <fstream>

using namespace std;

const string Empreinte::FICHIER_METADONNEES = "Metadonnees.txt";
const string Empreinte::FICHIER_EMPREINTES = "Empreintes.txt";

Empreinte::Empreinte() {}

Empreinte::Empreinte(int id, vector<Attribut*> liste) : listeAttributs(liste)
{
	NoID = id;
}

Empreinte::~Empreinte()
{
}

double Empreinte::distance(Empreinte e,vector<int> modele)
{
	double d = 0;
	vector<Attribut*> list1 = e.listeAttributs;
	for (unsigned int i = 0; i < modele.size(); i++) 
	{
		if (modele[i] == 0) 
		{
			d = d + listeAttributs[i]->distance(list1[i]);
		}
		else
		{
			d = d + listeAttributs[i]->distance(list1[i]);
		}
		
	}
	d = d / modele.size();
	return d;
}


int Empreinte::getID() const
{
	return NoID;
}

vector<Attribut*> Empreinte::getListeAttributs()
{
	return listeAttributs;
}

bool Empreinte::operator==(const Empreinte& e) const
{
	return (e.NoID == this->NoID);
}
