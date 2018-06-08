#include "stdafx.h"
#include "CppUnitTest.h"
#include "./../ApplicationMedical/Empreinte.h"
#include "./../ApplicationMedical/Attribut.h"
#include "./../ApplicationMedical/AttributString.h"
#include "./../ApplicationMedical/AttributDouble.h"
#include <vector>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsAttributString
{
	TEST_CLASS(TestsAttributString)
	{
		/*
		Cette classe de test regroupe les tests unitaires permettant de vérifier le bon fonctionnement
		de la classe AttributString
		*/
	public:

		TEST_METHOD(TestDistanceAttributString1)
		{
			/*
			Ce test unitaire permet de vérifier que l'appel de la méthode distance d'un objet sur lui-
			même retourne 0.0
			*/

			AttributString att("attribut", "contenu");
			double result = att.distance(&att);
			Assert::AreEqual(result, 0.0);
		}

		TEST_METHOD(TestDistanceAttributString2)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux AttributString
			ayant des valeurs différentes retourne 1.0
			*/

			AttributString att1("attribut1", "contenu1");
			AttributString att2("attribut2", "contenu2");
			double result1 = att1.distance(&att2);
			double result2 = att2.distance(&att1);
			Assert::AreEqual(result1, 1.0);
			Assert::AreEqual(result1, result2);
		}

		TEST_METHOD(TestDistanceAttributString3)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux AttributString
			distincts ayant des valeurs identiques retourne 0.0
			*/

			AttributString att1("attribut1", "contenu1&2");
			AttributString att2("attribut2", "contenu1&2");
			Assert::AreEqual(att1.distance(&att2), 0.0);
		}

	};
}