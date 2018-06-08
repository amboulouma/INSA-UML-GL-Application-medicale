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
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsGestionFichier
{
	TEST_CLASS(TestsGestionFichier)
	{
		/*
		Cette classe de test regroupe les tests unitaires permettant de vérifier le bon fonctionnement
		des fonctions de gestion de fichiers
		*/

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
				if (contenuF1.compare(contenuF2) != 0)
				{
					return false;
				}
			}
			if (!(f1.eof() && f2.eof()))
			{
				return false;
			}
			return true;
		}

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
				if (!(it->getNom()==it2->getNom()))
				{
					return false;
				}
			}
			return true;
		}

		bool comparerSchemas(vector<int> schema1, vector<int> schema2)
		{
			/*
			Cette fonction est utilisee dans les tests.
			Elle prend deux schemas d'attributs en parametre et retourne true s'ils ont un contenu
			identique et false sinon
			*/
			if (schema1.size() != schema2.size())
			{
				return false;
			}
			vector<int>::iterator it;
			vector<int>::iterator it2;
			for (it = schema1.begin(), it2 = schema2.begin(); it != schema1.end(), it2 != schema2.end(); ++it, ++it2)
			{
				if (!(*it == *it2))
				{
					return false;
				}
			}
			return true;
		}


		TEST_METHOD(TestAjouterDansBD1)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction ajouterDansBD
			dans une base de maladies vide. Ce test est valide avec un schema d'empreintes predefini
			qui est defini dans le fichier ModeleTestAjouterDansBD1.csv. Ce test verifie que la
			base des maladies a ete correctement modifiee et que la liste des maladies a ete
			correctement mise a jour
			*/

			std::ofstream Out("./../UnitTest1/fichiersTests/sortie.txt");
			std::streambuf* OldBuf = std::cout.rdbuf(Out.rdbuf());

			// Restauration du streambuf initial de std::cout (affichage sur la console) 
			

			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			gestionDonnees.setFichierMaladie("./../UnitTest1/fichiersTests/BaseMaladieTestAjouterDansBD1.csv");
			gestionFichier.setBdMaladie("./../UnitTest1/fichiersTests/BaseMaladieTestAjouterDansBD1.csv");

			gestionFichier.setDefEmpreinte("./../UnitTest1/fichiersTests/ModeleTestAnalyseSimple1.csv");

			gestionDonnees.defModele();

			gestionDonnees.calculerMaladies();

			list <Maladie> maladiesTheorique;
			list <Maladie> maladies;

			gestionDonnees.getMaladies(maladies);

			ifstream fichier1("./../UnitTest1/fichiersTests/TestAjouterDansBD1.csv", ios::in);

			bool opened = false;

			if (fichier1)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			vector <Attribut*> attributs1;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);

			attributs1.push_back(new AttributDouble("Att1", 0.5));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 1.5));
			attributs1.push_back(new AttributString("Att4", "content2"));
			attributs1.push_back(new AttributDouble("Att5", 2.5));

			Empreinte e1(1, attributs1);

			gestionFichier.ajouterDansBD(e1, "Myoclonie Phrenoglottique", schema);

			Maladie m("Myoclonie Phrenoglottique", e1);

			maladiesTheorique.push_back(m);

			ifstream fichier2(gestionFichier.getBdMaladie(), ios::in);

			opened = false;

			if (fichier2)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			Assert::IsTrue(comparerFichiers(fichier1, fichier2));

			
			Assert::IsTrue(comparerListesMaladies(maladiesTheorique, gestionDonnees.listMaladie));

			std::cout.rdbuf(OldBuf);
		}

		TEST_METHOD(TestAjouterDansBD2)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction ajouterDansBD
			dans une base de maladies contenant deja cette maladie. Ce test est valide avec un schema
			d'empreintes predefini qui est le suivant : double, string, double, string, double. Ce test
			verifie que la base des maladies a ete correctement modifiee et que la liste des maladies a ete
			correctement mise a jour. Ce test n'est valide que si le contenu de la base des maladies est le même
			que celui du fichier BaseMaladieTestAjouterDansBD2.csv
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			list <Maladie> maladiesTheorique;
			list <Maladie> maladies;

			vector<int> schema;

			gestionDonnees.getMaladies(maladies);

			gestionDonnees.getModele(schema);

			ifstream fichier1("./../UnitTest1/fichiersTests/TestAjouterDansBD2.csv", ios::in);

			bool opened = false;

			if (fichier1)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;
			vector <Attribut*> attributs3;

			attributs1.push_back(new AttributDouble("Att1", 0.5));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 1.5));
			attributs1.push_back(new AttributString("Att4", "content2"));
			attributs1.push_back(new AttributDouble("Att5", 2.5));

			attributs2.push_back(new AttributDouble("Att1", 1.5));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 2.5));
			attributs2.push_back(new AttributString("Att4", "content4"));
			attributs2.push_back(new AttributDouble("Att5", 3.5));

			attributs3.push_back(new AttributDouble("Att1", 1.0));
			attributs3.push_back(new AttributString("Att2", "content3"));
			attributs3.push_back(new AttributDouble("Att3", 2.0));
			attributs3.push_back(new AttributString("Att4", "content4"));
			attributs3.push_back(new AttributDouble("Att5", 3.0));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);
			Empreinte e3(3, attributs3); // e3 est l'empreinte moyenne de e1 et e2

			gestionFichier.ajouterDansBD(e1, "Myoclonie Phrenoglottique", schema); // On considere que cet ajout fonctionne car il a deja ete teste precedemment

			Maladie m("Myoclonie Phrenoglottique", e1);

			maladiesTheorique.push_back(m);

			gestionFichier.ajouterDansBD(e2, "Myoclonie Phrenoglottique", schema); // Cet ajout est celui qui sera reellement teste

			Maladie m2("Myoclonie Phrenoglottique", e3);

			maladiesTheorique.pop_back();

			maladiesTheorique.push_back(m2);

			//La maladie n'est pas ajoutee a la liste des maladies car elle existe deja mais elle est mise a jour

			/*ifstream fichier2(gestionFichier.BD_MALADIE, ios::in);

			opened = false;

			if (fichier2)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			Assert::IsTrue(comparerFichiers(fichier1, fichier2));

			Assert::IsTrue(comparerListesMaladies(maladiesTheorique, maladies));*/
		}

		TEST_METHOD(TestAjouterDansBD3)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction ajouterDansBD
			dans une base de maladies vide. Ce test est valide avec un schema d'empreintes predefini
			qui est le suivant : double, string, double, string, double. Ce test verifie que la
			base des maladies a ete correctement modifiee et que la liste des maladies a ete
			correctement mise a jour suite a plusieurs ajouts successifs
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			list <Maladie> maladiesTheorique;
			list <Maladie> maladies;

			vector<int> schema;

			gestionDonnees.getMaladies(maladies);

			gestionDonnees.getModele(schema);

			ifstream fichier1("./../UnitTest1/fichiersTests/TestAjouterDansBD3.csv", ios::in);

			bool opened = false;

			if (fichier1)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;
			vector <Attribut*> attributs3;
			vector <Attribut*> attributs4;

			attributs1.push_back(new AttributDouble("Att1", 0.5));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 1.5));
			attributs1.push_back(new AttributString("Att4", "content2"));
			attributs1.push_back(new AttributDouble("Att5", 2.5));

			attributs2.push_back(new AttributDouble("Att1", 1.5));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 2.5));
			attributs2.push_back(new AttributString("Att4", "content4"));
			attributs2.push_back(new AttributDouble("Att5", 3.5));

			attributs3.push_back(new AttributDouble("Att1", -12));
			attributs3.push_back(new AttributString("Att2", "rien"));
			attributs3.push_back(new AttributDouble("Att3", 3.2));
			attributs3.push_back(new AttributString("Att4", "quelconque"));
			attributs3.push_back(new AttributDouble("Att5", 65.2));

			attributs4.push_back(new AttributDouble("Att1", 1.0));
			attributs4.push_back(new AttributString("Att2", "content3"));
			attributs4.push_back(new AttributDouble("Att3", 2.0));
			attributs4.push_back(new AttributString("Att4", "content4"));
			attributs4.push_back(new AttributDouble("Att5", 3.0));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);
			Empreinte e3(3, attributs3);
			Empreinte e4(4, attributs4);

			gestionFichier.ajouterDansBD(e1, "Myoclonie Phrenoglottique", schema);
			Maladie m("Myoclonie Phrenoglottique", e1);
			maladiesTheorique.push_back(m);

			gestionFichier.ajouterDansBD(e2, "Typhus", schema);
			Maladie m2("Typhus", e2);
			maladiesTheorique.push_back(m2);

			gestionFichier.ajouterDansBD(e1, "Typhus", schema);
			maladiesTheorique.pop_back();
			Maladie m4("Typhus", e4);
			maladiesTheorique.push_back(m4);

			gestionFichier.ajouterDansBD(e3, "SIDA", schema);
			Maladie m3("SIDA", e3);
			maladiesTheorique.push_back(m3);

			gestionFichier.ajouterDansBD(e3, "SIDA", schema);

			/*ifstream fichier2(gestionFichier.BD_MALADIE, ios::in);

			opened = false;

			if (fichier2)
			{
				opened = true;
			}

			Assert::IsTrue(opened);

			Assert::IsTrue(comparerFichiers(fichier1, fichier2));

			Assert::IsTrue(comparerListesMaladies(maladiesTheorique, maladies));*/
		}

		TEST_METHOD(TestModeleEmpreinte1)
		{
			/*
			Ce test unitaire permet de vérifier de la fonction modeleEmpreinte
			dans le cas ou le contenu du fichier contenant le schema est le même que celui dans le
			fichier TestModeleEmpreinte1.csv
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;
			vector<int> schemaTheorique;

			vector<string> noms;
			vector<string> nomsTheoriques;

			gestionFichier.modeleEmpreinte(noms, schema);

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

		TEST_METHOD(TestModeleEmpreinte2)
		{
			/*
			Ce test unitaire permet de vérifier de la fonction modeleEmpreinte
			dans le cas ou le contenu du fichier contenant le schema est le même que celui dans le
			fichier TestModeleEmpreinte2.csv
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;
			vector<int> schemaTheorique;

			vector<string> noms;
			vector<string> nomsTheoriques;

			gestionFichier.modeleEmpreinte(noms, schema);

			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);
			schemaTheorique.push_back(0);
			schemaTheorique.push_back(1);

			nomsTheoriques.push_back("A1");
			nomsTheoriques.push_back("A2");
			nomsTheoriques.push_back("A3");
			nomsTheoriques.push_back("A4");
			nomsTheoriques.push_back("A5");
			nomsTheoriques.push_back("A6");
			nomsTheoriques.push_back("A7");
			nomsTheoriques.push_back("A8");
			nomsTheoriques.push_back("A9");
			nomsTheoriques.push_back("A10");
			nomsTheoriques.push_back("A11");
			nomsTheoriques.push_back("A12");
			nomsTheoriques.push_back("A13");

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

		TEST_METHOD(TestModeleEmpreinte3)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction modeleEmpreinte
			dans le cas ou le fichier contenant le schema est vide
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;
			vector<int> schemaTheorique;

			vector<string> noms;
			vector<string> nomsTheoriques;

			gestionFichier.modeleEmpreinte(noms, schema);

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

		TEST_METHOD(TestLireBD1)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction lireBD quand le contenu
			de la base des maladies est le même que celui du fichier TestLireBD1.csv
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;

			unordered_map<string, Empreinte> liste;
			unordered_map<string, Empreinte> listeTheorique;

			gestionFichier.lireBD(liste, schema);

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

			listeTheorique.insert(make_pair("Maladie1", e3));
			listeTheorique.insert(make_pair("Maladie2", e1));
			listeTheorique.insert(make_pair("", e2));

			bool success = false;

			if (liste == listeTheorique)
			{
				success = true;
			}

			Assert::IsTrue(success);
		}

		TEST_METHOD(TestLireEmpreinte1)
		{
			/*
			Ce test unitaire permet de vérifier le bon fonctionnement de la fonction lireEmpreinte quand le contenu
			de la base d'empreintes est le même que celui du fichier TestLireEmpreinte1.csv
			*/
			GestionFichier gestionFichier;
			GestionDonnees gestionDonnees;

			vector<int> schema;

			vector<string> noms;

			vector<Empreinte> empreintes;
			vector<Empreinte> empreintesTheorique;

			gestionFichier.modeleEmpreinte(noms, schema);

			gestionFichier.lireEmpreinte(empreintes, schema, noms);

			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

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

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			empreintesTheorique.push_back(e1);
			empreintesTheorique.push_back(e2);
		}
	};
}