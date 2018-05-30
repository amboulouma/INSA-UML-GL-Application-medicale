#include "Empreinte.h"
#include <fstream>

using namespace std;

const string Empreinte::FICHIER_METADONNEES = "Metadonnees.txt";
const string Empreinte::FICHIER_EMPREINTES = "Empreintes.txt";
vector<int> Empreinte::modele;

Empreinte::Empreinte() {}

Empreinte::Empreinte(int id, vector<Attribut *> liste) : listeAttributs(liste)
{
	NoID = id;
	if (Empreinte::modele.empty())
	{
		string line;
		ifstream is(FICHIER_METADONNEES);
		while (getline(is, line))
		{
			int pos = line.find(';');
			string type = line.substr(pos + 1);
			if (type == "string")
			{
				Empreinte::modele.push_back(0);
			}
			else if (type == "double")
			{
				Empreinte::modele.push_back(1);
			}
		}
		is.close();
	}
}

Empreinte::~Empreinte()
{
}

double Empreinte::distance(Empreinte e)
{
	double d = 0;
	vector<Attribut *> list1 = e.listeAttributs;
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
	return d;
}

void Empreinte::sauvegarderEmpreinte()
{
	ofstream os;
	os.open(FICHIER_EMPREINTES, std::ofstream::out | std::ofstream::app);
	os << NoID;
	for (int i = 0; i < listeAttributs.size(); i++)
	{
		if (modele[i]==0)
		{
			AttributString* as = dynamic_cast<AttributString*>(listeAttributs[i]);
			os << ";" << as->getData();
		} 
		else
		{
			AttributDouble* ad = dynamic_cast<AttributDouble*>(listeAttributs[i]);
			os << ";" << ad->getData();
		}
	}
	os << endl;
	os.close();
}