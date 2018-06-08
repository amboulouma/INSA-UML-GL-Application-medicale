#include "stdafx.h"
#include "CppUnitTest.h"
#include "./../ApplicationMedical/Empreinte.h"
#include "./../ApplicationMedical/Attribut.h"
#include "./../ApplicationMedical/AttributString.h"
#include "./../ApplicationMedical/AttributDouble.h"
#include "./../ApplicationMedical/Maladie.h"
#include "./../ApplicationMedical/GestionFichier.h"
#include "./../ApplicationMedical/GestionDonnees.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsDefinitionDonnees
{
	TEST_CLASS(TestsDefinitionDonnees)
	{
		bool comparerListesMaladies(list <Maladie> &m1, list <Maladie> &m2)
		{
			/*
			Cette fonction est utilisee dans les tests.
			Elle prend deux listes de maladies en parametre et retourne true si les listes ont un contenu
			identique et false sinon
			*/
			if (m1.size() != m2.size())
			{
				return false;
			}
			list<Maladie>::iterator it;
			list<Maladie>::iterator it2;
			for (it = m1.begin(), it2 = m2.begin(); it != m1.end(), it2 != m2.end(); ++it, ++it2)
			{
				if (!(*it == *it2))
				{
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(TestDefMaladie1)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction defMaladie quand le contenu
			de la base de maladies est le même que celui du fichier TestDefMaladie1.csv
			*/
			std::ofstream Out("./../UnitTest1/fichiersTests/sortie.txt");
			std::streambuf* OldBuf = std::cout.rdbuf(Out.rdbuf());

			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;

			unordered_map<string, Empreinte> liste;

			list<Maladie> maladies;
			list<Maladie> maladiestheorique;

			gestionFichier.lireBD(liste, schema);

			gestionDonnees.calculerMaladies();

			gestionDonnees.getMaladies(maladies);

			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;
			vector <Attribut*> attributs3;

			attributs1.push_back(new AttributDouble("A1", 0.5));
			attributs1.push_back(new AttributString("A2", "content"));
			attributs1.push_back(new AttributDouble("A3", 1.5));
			attributs1.push_back(new AttributString("A4", "content2"));
			attributs1.push_back(new AttributDouble("A5", 2.5));

			attributs2.push_back(new AttributDouble("A1", 1.5));
			attributs2.push_back(new AttributString("A2", "content3"));
			attributs2.push_back(new AttributDouble("A3", 2.5));
			attributs2.push_back(new AttributString("A4", "content4"));
			attributs2.push_back(new AttributDouble("A5", 3.5));

			attributs3.push_back(new AttributDouble("A1", 1.0));
			attributs3.push_back(new AttributString("A2", "content3"));
			attributs3.push_back(new AttributDouble("A3", 2.0));
			attributs3.push_back(new AttributString("A4", "content4"));
			attributs3.push_back(new AttributDouble("A5", 3.0));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);
			Empreinte e3(4, attributs3);

			Maladie m1("Maladie1", e3);
			Maladie m2("Maladie2", e1);
			Maladie m3("", e2);

			maladiestheorique.push_back(m1);
			maladiestheorique.push_back(m2);
			maladiestheorique.push_back(m3);

			

			list<Maladie>::iterator it;
			for (Maladie m : gestionDonnees.listMaladie)
			{
				std::cout << m.getNom() << std::endl;
			}

			for (Maladie m : maladiestheorique)
			{
				std::cout << m.getNom() << std::endl;
			}

			Assert::IsTrue(comparerListesMaladies(maladies, maladiestheorique));
			std::cout.rdbuf(OldBuf);
		}

		TEST_METHOD(TestDefModeleEmpreinte1)
		{
			/*
			Ce test unitaire permet de vérifier de la fonction defModeleEmpreinte
			dans le cas ou le contenu du fichier contenant le schema est le même que celui dans le
			fichier TestDefModeleEmpreinte1.csv
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;
			vector<int> schemaTheorique;

			vector<string> noms;
			vector<string> nomsTheoriques;

			gestionDonnees.defModele();

			gestionDonnees.getModele(schema);
			gestionDonnees.getNomsAttributs(noms);

			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(1);

			nomsTheoriques.push_back("A1");
			nomsTheoriques.push_back("A2");
			nomsTheoriques.push_back("A3");
			nomsTheoriques.push_back("A4");

			bool success = false;

			if (schema == schemaTheorique)
			{
				success = true;
			}

			if (noms == nomsTheoriques)
			{
				success = true;
			}

			Assert::IsTrue(success);
		}
	};
}