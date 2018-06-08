#include "stdafx.h"
#include "CppUnitTest.h"
#include "./../ApplicationMedical/Empreinte.h"
#include "./../ApplicationMedical/Attribut.h"
#include "./../ApplicationMedical/AttributString.h"
#include "./../ApplicationMedical/AttributDouble.h"
#include <vector>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsEmpreintes
{
	TEST_CLASS(TestsEmpreintes)
	{
		/*
		Cette classe de test regroupe les tests unitaires permettant de vérifier le bon fonctionnement
		de la classe Empreinte
		*/
		TEST_METHOD(TestEmpreintes1)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux empreintes
			distinctes ayant des valeurs identiques retourne 0.0
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

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			Assert::AreEqual(e1.distance(e2, schema), 0.0);
			Assert::AreEqual(e2.distance(e1, schema), 0.0);
			Assert::AreEqual(e1.distance(e2, schema), e2.distance(e1, schema));
		}

		TEST_METHOD(TestEmpreintes2)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à une empreinte
			sur elle même retourne 0.0
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
			attributs1.push_back(new AttributDouble("Att3", 0.2));
			attributs1.push_back(new AttributString("Att4", "content2"));
			attributs1.push_back(new AttributDouble("Att5", -0.4));

			Empreinte e1(1, attributs1);

			Assert::AreEqual(e1.distance(e1, schema), 0.0);
		}


		TEST_METHOD(TestEmpreintes3)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux empreintes
			distinctes ayant des valeurs différentes avec pour chaque attribut des distances egales
			a 1.0 retourne 1.0
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);

			attributs1.push_back(new AttributDouble("Att1", 0.0));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 0.0));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", 1.0));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 1.0));
			attributs2.push_back(new AttributString("Att4", "content4"));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			Assert::AreEqual(e1.distance(e2, schema), 1.0);
			Assert::AreEqual(e2.distance(e1, schema), 1.0);
			Assert::AreEqual(e2.distance(e1, schema), e1.distance(e2, schema));
		}

		TEST_METHOD(TestEmpreintes4)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux empreintes
			distinctes ayant les valeurs precisees dans le test retourne 0.5
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);

			attributs1.push_back(new AttributDouble("Att1", -153.12));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 17.42));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", 666.66));
			attributs2.push_back(new AttributString("Att2", "content"));
			attributs2.push_back(new AttributDouble("Att3", 32.0));
			attributs2.push_back(new AttributString("Att4", "content2"));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			Assert::AreEqual(e1.distance(e2, schema), 0.5);
			Assert::AreEqual(e2.distance(e1, schema), 0.5);
			Assert::AreEqual(e2.distance(e1, schema), e1.distance(e2, schema));
		}

		TEST_METHOD(TestEmpreintes5)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux empreintes
			distinctes ayant les valeurs precisees dans le test retourne 0.3325
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);

			attributs1.push_back(new AttributDouble("Att1", -0.12));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 0.42));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", 0.66));
			attributs2.push_back(new AttributString("Att2", "content"));
			attributs2.push_back(new AttributDouble("Att3", 0.97));
			attributs2.push_back(new AttributString("Att4", "content2"));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			Assert::AreEqual(e1.distance(e2, schema), 0.3325);
			Assert::AreEqual(e2.distance(e1, schema), 0.3325);
			Assert::AreEqual(e2.distance(e1, schema), e1.distance(e2, schema));
		}

		TEST_METHOD(TestEmpreintes6)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux empreintes
			distinctes ayant les valeurs precisees dans le test retourne 0.625
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);

			attributs1.push_back(new AttributDouble("Att1", -14.2));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", -8.8));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", -13.7));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 3.6));
			attributs2.push_back(new AttributString("Att4", "content2"));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			Assert::AreEqual(e1.distance(e2, schema), 0.625);
			Assert::AreEqual(e2.distance(e1, schema), 0.625);
			Assert::AreEqual(e2.distance(e1, schema), e1.distance(e2, schema));
		}

		TEST_METHOD(TestEmpreintes7)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux empreintes
			distinctes ayant les valeurs precisees dans le test retourne 0.5
			*/
			vector <Attribut*> attributs1;
			vector <Attribut*> attributs2;

			vector<int> schema;

			schema.push_back(1);
			schema.push_back(0);
			schema.push_back(1);
			schema.push_back(0);

			attributs1.push_back(new AttributDouble("Att1", -14.2));
			attributs1.push_back(new AttributString("Att2", "content"));
			attributs1.push_back(new AttributDouble("Att3", 3.6));
			attributs1.push_back(new AttributString("Att4", "content2"));

			attributs2.push_back(new AttributDouble("Att1", -14.2));
			attributs2.push_back(new AttributString("Att2", "content3"));
			attributs2.push_back(new AttributDouble("Att3", 3.6));
			attributs2.push_back(new AttributString("Att4", "content4"));

			Empreinte e1(1, attributs1);
			Empreinte e2(2, attributs2);

			Assert::AreEqual(e1.distance(e2, schema), 0.5);
			Assert::AreEqual(e2.distance(e1, schema), 0.5);
			Assert::AreEqual(e2.distance(e1, schema), e1.distance(e2, schema));
		}
	};
}