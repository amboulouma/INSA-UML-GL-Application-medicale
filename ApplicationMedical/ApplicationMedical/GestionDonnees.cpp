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
	std::cout << "lol" << std::endl;
	for (auto i = liste.begin(); i != liste.end(); ++i)
	{
		std::cout << "Coucou" << std::endl;
		Maladie m(i->first, i->second);
		listMaladie.push_back(m);
	}
	
}

void GestionDonnees::analyse(const Empreinte &e)
{
	unordered_map<string, double> resultat;
	for (Maladie m : listMaladie) 
	{
		double probab = m.presence(e,modele);
		resultat.insert(make_pair(m.getNom(), probab));
	}

	cout << e.getID() << endl;
	for (auto i = resultat.begin(); i != resultat.end(); ++i)
	{
		cout << "     Maladie: " << i->first << " | Probabilite: " << i->second << endl;
	}
}

void GestionDonnees::analyse(list<Empreinte> listeEmpreintes)
{
	for (Empreinte e : listeEmpreintes)
	{
		analyse(e);
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

void GestionDonnees::getMaladies(list<Maladie> & maladies)
{
	list<Maladie>::iterator it;
	for (it = listMaladie.begin(); it != listMaladie.end(); ++it)
	{
		maladies.push_back(*it);
	}
}

void GestionDonnees::getModele(vector<int>& schema)
{
	vector<int>::iterator it;
	for (it = modele.begin(); it != modele.end(); ++it)
	{
		schema.push_back(*it);
	}
}

void GestionDonnees::getNomsAttributs(vector<string>& noms)
{
	vector<string>::iterator it;
	for (it = nomAttribut.begin(); it != nomAttribut.end(); ++it)
	{
		noms.push_back(*it);
	}
}

string GestionDonnees::getFichierMaladie()
{
	return FICHIER_MALADIE;
}

string GestionDonnees::getFichierEmpreintes()
{
	return FICHIER_EMPREINTES;
}

void GestionDonnees::setFichierMaladie(const string & fichierMaladie)
{
	FICHIER_MALADIE = fichierMaladie;
}

void GestionDonnees::setFichierEmpreintes(const string & fichierEmpreintes)
{
	FICHIER_EMPREINTES = fichierEmpreintes;
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