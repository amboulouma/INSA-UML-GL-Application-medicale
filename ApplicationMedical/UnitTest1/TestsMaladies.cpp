#include "stdafx.h"
#include "CppUnitTest.h"
#include "./../ApplicationMedical/Empreinte.h"
#include "./../ApplicationMedical/Attribut.h"
#include "./../ApplicationMedical/AttributString.h"
#include "./../ApplicationMedical/AttributDouble.h"
#include "./../ApplicationMedical/Maladie.h"
#include <vector>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsMaladies
{
	TEST_CLASS(TestsMaladies)
	{
		/*
		Cette classe de test regroupe les tests unitaires permettant de vérifier le bon fonctionnement
		de la classe Maladie
		*/
		TEST_METHOD(TestMaladies1)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie 
			ayant une empreinte moyenne avec des valeurs d'attributs identiques à celle
			passee en parametre retourne une probabilité de 1.0
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

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

			attributs2.push_back(new AttributDouble("Att1", 0.5));
			attributs2.push_back(new AttributString("Att2", "content"));
			attributs2.push_back(new AttributDouble("Att3", 1.5));
			attributs2.push_back(new AttributString("Att4", "content2"));
			attributs2.push_back(new AttributDouble("Att5", 2.5));

			Empreinte empreinteMoyenne(1, attributs1);
			Empreinte empreinteATester(2, attributs2);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteATester, schema), 1.0);
		}

		TEST_METHOD(TestMaladies2)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie
			ayant une empreinte moyenne et une empreinte passee en parametre vides retourne une
			probabilite de 1.0
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			Empreinte empreinteMoyenne(1, attributs1);
			Empreinte empreinteATester(2, attributs2);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteATester, schema), 1.0);
		}

		TEST_METHOD(TestMaladies3)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie
			avec comme parametre son empreinte moyenne retourne une probabilite de 1.0
			*/
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

			Empreinte empreinteMoyenne(1, attributs1);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteMoyenne, schema), 1.0);
		}

		TEST_METHOD(TestMaladies4)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie
			ayant une empreinte moyenne avec ces valeurs d'attributs et une empreinte
			passee en parametre avec ces valeurs d'attributs retourne une probabilité de 0.5
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);

			attributs1.push_back(new AttributDouble("Att1", -153.12));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 17.42));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", 666.66));
			attributs2.push_back(new AttributString("Att2", "content"));
			attributs2.push_back(new AttributDouble("Att3", 32.0));
			attributs2.push_back(new AttributString("Att4", "content2"));

			Empreinte empreinteMoyenne(1, attributs1);
			Empreinte empreinteATester(2, attributs2);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteATester, schema), 0.5);
		}

		TEST_METHOD(TestMaladies5)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie
			ayant une empreinte moyenne avec ces valeurs d'attributs et une empreinte
			passee en parametre avec ces valeurs d'attributs retourne une probabilité de 0.6675
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);

			attributs1.push_back(new AttributDouble("Att1", -0.12));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 0.42));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", 0.66));
			attributs2.push_back(new AttributString("Att2", "content"));
			attributs2.push_back(new AttributDouble("Att3", 0.97));
			attributs2.push_back(new AttributString("Att4", "content2"));

			Empreinte empreinteMoyenne(1, attributs1);
			Empreinte empreinteATester(2, attributs2);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteATester, schema), 0.6675);
		}

		TEST_METHOD(TestMaladies6)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie
			ayant une empreinte moyenne avec ces valeurs d'attributs et une empreinte
			passee en parametre avec ces valeurs d'attributs retourne une probabilité de 0.375
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);

			attributs1.push_back(new AttributDouble("Att1", -14.2));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", -8.8));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", -13.7));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 3.6));
			attributs2.push_back(new AttributString("Att4", "content2"));

			Empreinte empreinteMoyenne(1, attributs1);
			Empreinte empreinteATester(2, attributs2);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteATester, schema), 0.375);
		}

		TEST_METHOD(TestMaladies7)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode presence appliquee sur une maladie
			ayant une empreinte moyenne avec ces valeurs d'attributs et une empreinte
			passee en parametre avec ces valeurs d'attributs retourne une probabilité de 0.5
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);

			attributs1.push_back(new AttributDouble("Att1", -14.2));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 3.6));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", -14.2));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 3.6));
			attributs2.push_back(new AttributString("Att4", "content4"));

			Empreinte empreinteMoyenne(1, attributs1);
			Empreinte empreinteATester(2, attributs2);

			Maladie m("Myoclonie Phrenoglottique", empreinteMoyenne);

			Assert::AreEqual(m.presence(empreinteATester, schema), 0.5);
		}
	};
}