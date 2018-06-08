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

namespace TestsDiagnostic
{
	TEST_CLASS(TestsDiagnostic)
	{
		bool comparerFichiers(ifstream &f1, ifstream &f2)
		{
			/*
			Cette fonction est utilisee dans les tests.
			Elle prend deux flux sur fichiers en parametre et retourne true si les fichiers ont un contenu
			identique et false sinon
			*/
			string contenuF1;
			string contenuF2;
			while (f1 && f2)
			{
				getline(f1, contenuF1);
				getline(f2, contenuF2);
				if (contenuF1.compare(contenuF2))
				{
					return false;
				}
			}
			if (f1 || f2)
			{
				return false;
			}
			return true;
		}

		TEST_METHOD(TestAnalyseSimple1)
		{
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector <Attribut*> attributs4;

			attributs4.push_back(new AttributDouble("A1", 15.0));
			attributs4.push_back(new AttributString("A2", "content5"));
			attributs4.push_back(new AttributDouble("A3", -2.0));
			attributs4.push_back(new AttributString("A4", "content6"));
			attributs4.push_back(new AttributDouble("A5", 3.6));

			Empreinte empreinteAAnalyser(5, attributs4);

			/*std::ofstream Out("./../UnitTest1/fichiersTests/SortieTestAnalyseSimple1.csv");
			std::streambuf* OldBuf = std::cout.rdbuf(Out.rdbuf());*/

			gestionDonnees.analyse(empreinteAAnalyser);

			//std::cout.rdbuf(OldBuf);

			ifstream fichier1("./../UnitTest1/fichiersTests/SortieAttendueTestAnalyseSimple1.csv", ios::in);

			bool opened = false;

			if (fichier1)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			ifstream fichier2("./../UnitTest1/fichiersTests/SortieTestAnalyseSimple1.csv", ios::in);

			opened = false;

			if (fichier2)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			Assert::IsTrue(comparerFichiers(fichier1, fichier2));
		}

		TEST_METHOD(TestAnalyseListe)
		{

		}
	};
}