#include "stdafx.h"
#include "GestionDonnees.h"
#include "GestionFichier.h"
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

GestionDonnees::GestionDonnees() 
{
	defModele();
	calculerMaladies();
}

GestionDonnees::~GestionDonnees() {}

void GestionDonnees::defModele()
{
	GestionFichier gf;
	if (modele.empty())
	{
		gf.modeleEmpreinte(nomAttribut, modele);
	}
}

void GestionDonnees::calculerMaladies()
{
	GestionFichier gf;
	listMaladie.clear();
	unordered_map<string, Empreinte> liste;
	gf.lireBD(liste, modele);
	for (auto i = liste.begin(); i != liste.end(); ++i)
	{
		Maladie m(i->first, i->second);
		listMaladie.push_back(m);
	}
}

unordered_map<string, double> GestionDonnees::analyse(Empreinte e)
{
	unordered_map<string, double> resultat;
	for (Maladie m : listMaladie) 
	{
		double probab = m.presence(e,modele);
		resultat.insert(make_pair(m.getNom(), probab));
	}

	return resultat;
}

void GestionDonnees::analyse(list<Empreinte> listeEmpreintes)
{
	for (Empreinte e : listeEmpreintes)
	{
		unordered_map<string, double> resultat = analyse(e);
		cout << e.getID() << endl;
		for (auto i = resultat.begin(); i != resultat.end(); ++i)
		{
			cout << "     Maladie: " << i->first << " | Probabilite: " << i->second << endl;
		}
	}
}

void GestionDonnees::associerMaladieEmpreinte(string maladie, Empreinte e)
{
	GestionFichier gf;
	gf.ajouterDansBD(e, maladie, modele);
	calculerMaladies();
}

Empreinte GestionDonnees::trouverEmpreinteParID(int id)
{
	ifstream is(Empreinte::FICHIER_EMPREINTES);
	string line;
	getline(is, line);
	while (getline(is, line))
	{
		string idEmpreinteString = line.substr(0, line.find(';'));
		int idEmpreinte = stoi(idEmpreinteString);
		if (idEmpreinte == id)
		{
			vector<string> attribut = splitLine(line, ';');
			vector<Attribut*> liste;
			for (int i = 0; i < modele.size(); i++)
			{
				if (modele[i] == 0)
				{
					Attribut* a = new AttributString(nomAttribut[i],attribut[i+1]);
					liste.push_back(a);
				}
				else if (modele[i] == 1)
				{
					int val = stod(attribut[i + 1]);
					Attribut* a = new AttributDouble(nomAttribut[i], val);
					liste.push_back(a);
				}
			}
			Empreinte e(idEmpreinte, liste);
			return e;
		}
		
	}
}

vector<string> GestionDonnees::splitLine(string line, char c = ' ')
{
	vector<string> result;
	const char* str = line.c_str();
	do
	{
		const char *begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
}