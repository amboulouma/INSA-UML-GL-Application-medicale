#include "stdafx.h"
#include "GestionDonnees.h"
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

GestionDonnees::GestionDonnees()
{
	genererListeMaladie();
}

GestionDonnees::~GestionDonnees() {}

void GestionDonnees::genererListeMaladie()
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

	listMaladie.clear();

	ifstream is;
	is.open(FICHIER_MALADIE);
	string line;
	getline(is, line);
	vector<string> nomAttribut = splitLine(line, ';');
	unordered_map<string, int> nombrePresenceMaladie;
	unordered_map<string, vector<double>> sommeDonneesAttribut;
	unordered_map<string, vector<string>> stringMoy;
	while (getline(is, line))
	{
		vector<Attribut *> list;
		vector<string> attribut = splitLine(line, ';');
		string nomMaladie = attribut[attribut.size() - 1];
		nombrePresenceMaladie[nomMaladie]++;
		int ID = stoi(attribut[0]);
		sommeDonneesAttribut[nomMaladie].push_back(ID);
		stringMoy[nomMaladie].push_back("!");

		for (int i = 1; i < attribut.size() - 1; i++)
		{
			sommeDonneesAttribut[nomMaladie].push_back(0);
			stringMoy[nomMaladie].push_back("!");
		}
		for (int i = 1; i < attribut.size() - 1; i++)
		{
			if (Empreinte::modele[i - 1] == 1)
			{
				sommeDonneesAttribut[nomMaladie][i] += stod(attribut[i]);
			}
			else if (Empreinte::modele[i - 1] == 0)
			{
				sommeDonneesAttribut[nomMaladie][i] = -1;
				stringMoy[nomMaladie][i] = attribut[i];
			}
		}
	}
	is.close();
	for (auto i = nombrePresenceMaladie.begin(); i != nombrePresenceMaladie.end(); ++i)
	{
		vector<Attribut *> list;
		string nomMaladie = i->first;
		for (int j = 0; j < Empreinte::modele.size(); j++)
		{
			if (Empreinte::modele[j] == 0)
			{
				Attribut *attribut = new AttributString(Empreinte::nomAttribut[j], stringMoy[nomMaladie][j + 1]);
				list.push_back(attribut);
			}
			else if (Empreinte::modele[j] == 1)
			{
				double moy = sommeDonneesAttribut[nomMaladie][j + 1] / nombrePresenceMaladie[nomMaladie];
				Attribut *attribut = new AttributDouble(Empreinte::nomAttribut[j], moy);
				list.push_back(attribut);
			}
		}
		Empreinte empreinte(sommeDonneesAttribut[nomMaladie][0], list);
		Maladie maladie(nomMaladie, empreinte);
		listMaladie.push_back(maladie);
	}
}

unordered_map<string, double> GestionDonnees::analyse(Empreinte e)
{
	unordered_map<string, double> resultat;
	for (Maladie maladie : listMaladie)
	{
		double probab = maladie.presence(e);
		resultat.insert(make_pair(maladie.getNom(), probab));
	}

	return resultat;
}

void GestionDonnees::analyse(list<Empreinte> listeEmpreintes)
{
	for (Empreinte empreinte : listeEmpreintes)
	{
		unordered_map<string, double> resultat = analyse(empreinte);
		cout << empreinte.getID() << endl;
		for (auto i = resultat.begin(); i != resultat.end(); ++i)
		{
			cout << "     Maladie: " << i->first << " | Probabilite: " << i->second << endl;
		}
	}
}

void GestionDonnees::associerMaladieEmpreinte(string maladie, Empreinte empreinte)
{
	ofstream os;
	os.open(FICHIER_MALADIE, ofstream::out | ofstream::app);
	os << empreinte.getID();
	vector<Attribut *> listeAttributs = empreinte.listeAttributs;
	for (int i = 0; i < listeAttributs.size(); i++)
	{
		if (Empreinte::modele[i] == 0)
		{
			AttributString *attributString = dynamic_cast<AttributString *>(listeAttributs[i]);
			os << ";" << attributString->getData();
		}
		else
		{
			AttributDouble *attributDouble = dynamic_cast<AttributDouble *>(listeAttributs[i]);
			os << ";" << attributDouble->getData();
		}
	}
	os << ";" << maladie << endl;
	os.close();
	genererListeMaladie();
}

vector<string> GestionDonnees::splitLine(string line, char c = ' ')
{
	vector<string> result;
	const char *str = line.c_str();
	do
	{
		const char *begin = str;

		while (*str != c && *str)
			str++;

		result.push_back(string(begin, str));
	} while (0 != *str++);

	return result;
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
			vector<Attribut *> liste;
			for (int i = 0; i < Empreinte::modele.size(); i++)
			{
				if (Empreinte::modele[i] == 0)
				{
					Attribut *attribut = new AttributString(Empreinte::nomAttribut[i], attribut[i + 1]);
					liste.push_back(attribut);
				}
				else if (Empreinte::modele[i] == 1)
				{
					int valeur = stod(attribut[i + 1]);
					Attribut *attribut = new AttributDouble(Empreinte::nomAttribut[i], valeur);
					liste.push_back(attribut);
				}
			}
			Empreinte empreinte(idEmpreinte, liste);
			return empreinte;
		}
	}
}