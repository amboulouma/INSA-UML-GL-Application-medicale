#include "GestionFichier.h"

#include <fstream>

using namespace std;

GestionFichier::GestionFichier() {}

GestionFichier::~GestionFichier() {}

void GestionFichier::ajouterDansBD(Empreinte& e, string nomMaladie, vector<int>& modele)
{
	ofstream os;
	os.open(BD_MALADIE, ofstream::out | ofstream::app);
	os << e.getID();
	vector<Attribut*> listeAttributs = e.listeAttributs;
	for (int i = 0; i < listeAttributs.size(); i++)
	{
		if (modele[i] == 0)
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
	os << ";" << nomMaladie << endl;
	os.close();
}

void GestionFichier::modeleEmpreinte(vector<string>& nomAttribut, vector<int>& modele)
{
	string line;
	ifstream is(DEF_EMPREINTE);
	while (getline(is, line))
	{
		int pos = line.find(';');
		string type = line.substr(pos + 1);
		string nomAtt = line.substr(0, pos);
		if (type == "string")
		{
			modele.push_back(0);
			nomAttribut.push_back(nomAtt);
		}
		else if (type == "double")
		{
			modele.push_back(1);
			nomAttribut.push_back(nomAtt);
		}
	}
	is.close();
}

void GestionFichier::lireBD(unordered_map<string, Empreinte>& liste, vector<int>& modele)
{
	liste.clear();
	ifstream is;
	is.open(BD_MALADIE);
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
			if (modele[i - 1] == 1)
			{
				sum[nomMaladie][i] += stod(attribut[i]);
			}
			else if (modele[i - 1] == 0)
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
		for (int j = 0; j < modele.size(); j++)
		{
			if (modele[j] == 0)
			{
				Attribut* a = new AttributString(nomAttribut[j], stringMoy[nomMaladie][j + 1]);
				list.push_back(a);
			}
			else if (modele[j] == 1)
			{
				double moy = sum[nomMaladie][j + 1] / n[nomMaladie];
				Attribut* a = new AttributDouble(nomAttribut[j], moy);
				list.push_back(a);
			}
		}
		Empreinte e(sum[nomMaladie][0], list);
		liste.insert(make_pair(nomMaladie, e));
	}
}

void GestionFichier::lireEmpreinte(vector<Empreinte>& listEmpreinte, vector<int> modele, vector<string> nomAttribut)
{
	listEmpreinte.clear();
	ifstream is(ANALYSE_EMPREINTE);
	string line;
	getline(is, line);
	while (getline(is, line))
	{
		string idEmpreinteString = line.substr(0, line.find(';'));
		int idEmpreinte = stoi(idEmpreinteString);
		vector<string> attribut = splitLine(line, ';');
		vector<Attribut*> liste;
		for (int i = 0; i < modele.size(); i++)
		{
			if (modele[i] == 0)
			{
				Attribut* a = new AttributString(nomAttribut[i], attribut[i + 1]);
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
		listEmpreinte.push_back(e);
	}
	is.close();
}

vector<string> GestionFichier::splitLine(string line, char c = ' ')
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