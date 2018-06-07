#include "stdafx.h"
#include "GestionDonnees.h"
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

GestionDonnees::GestionDonnees() 
{
	if (Empreinte::modele.empty())
	{
		string line;
		ifstream is1(Empreinte::FICHIER_METADONNEES);
		while (getline(is1, line))
		{
			int pos = line.find(';');
			string type = line.substr(pos + 1);
			string nomAtt = line.substr(0, pos);
			if (type == "string")
			{
				Empreinte::modele.push_back(0);
				Empreinte::nomAttribut.push_back(nomAtt);
			}
			else if (type == "double")
			{
				Empreinte::modele.push_back(1);
				Empreinte::nomAttribut.push_back(nomAtt);
			}
		}
		is1.close();
	}

	ifstream is;
	is.open(FICHIER_MALADIE);
	string line;
	getline(is, line);
	vector<string> nomAttribut = splitLine(line, ';');
	unordered_map<string, int> n; //nombre de presence d'une maladie dans le fichier
	unordered_map<string, vector<double>> sum; //somme des donnees d'un attribut de meme maladie, sum = -1 si un attribut string
	unordered_map<string, vector<string>> stringMoy;
	while (getline(is, line))
	{
		vector<Attribut*> list;
		vector<string> attribut = splitLine(line, ';');
		string nomMaladie = attribut[attribut.size() - 1];
		n[nomMaladie]++;
		int ID = stoi(attribut[0]);
		sum[nomMaladie].push_back(ID);
		stringMoy[nomMaladie].push_back("!");

		for (int i = 1; i < attribut.size() - 1; i++)
		{
			sum[nomMaladie].push_back(0);
			stringMoy[nomMaladie].push_back("!");
		}
		for (int i = 1; i < attribut.size() - 1; i++)
		{
			if (Empreinte::modele[i-1] == 1)
			{
				sum[nomMaladie][i] += stod(attribut[i]);
			}
			else if (Empreinte::modele[i-1] == 0)
			{
				sum[nomMaladie][i] = -1;
				stringMoy[nomMaladie][i] = attribut[i];
			}
		}
	}
	is.close();
	for (auto i = n.begin(); i != n.end(); ++i)
	{
		vector<Attribut*> list;
		string nomMaladie = i->first;
		for (int j = 0; j < Empreinte::modele.size(); j++) 
		{
			if (Empreinte::modele[j] == 0) 
			{
				Attribut* a = new AttributString(Empreinte::nomAttribut[j],stringMoy[nomMaladie][j+1]);
				list.push_back(a);
			} 
			else if (Empreinte::modele[j] == 1) 
			{
				double moy = sum[nomMaladie][j + 1] / n[nomMaladie];
				Attribut* a = new AttributDouble(Empreinte::nomAttribut[j], moy);
				list.push_back(a);
			}
		}
		Empreinte e(sum[nomMaladie][0], list);
		Maladie m(nomMaladie, e);
		listMaladie.push_back(m);
	}
}

GestionDonnees::~GestionDonnees() {}

unordered_map<string, double> GestionDonnees::analyse(Empreinte e)
{
	unordered_map<string, double> resultat;
	for (Maladie m : listMaladie) 
	{
		double probab = m.presence(e);
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
	ofstream os;
	os.open(FICHIER_MALADIE, ofstream::out | ofstream::app);
	os << e.getID();
	vector<Attribut*> listeAttributs = e.listeAttributs;
	for (int i = 0; i < listeAttributs.size(); i++)
	{
		if (Empreinte::modele[i] == 0)
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
	os << ";" << maladie << endl;
	os.close();
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