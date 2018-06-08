#include "stdafx.h"
#include "CppUnitTest.h"
#include "./../ApplicationMedical/Empreinte.h"
#include "./../ApplicationMedical/Attribut.h"
#include "./../ApplicationMedical/AttributString.h"
#include "./../ApplicationMedical/AttributDouble.h"
#include <vector>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsAttributDouble
{
	TEST_CLASS(TestsAttributDouble)
	{
		/*
		Cette classe de test regroupe les tests unitaires permettant de vérifier le bon fonctionnement
		de la classe AttributDouble
		*/
	public:
		TEST_METHOD(TestDistanceAttributDouble1)
		{
			/*
			Ce test unitaire permet de vérifier que l'appel de la méthode distance d'un objet sur lui-
			même retourne 0.0
			*/

			AttributDouble att("attribut", 3.14);
			double result = att.distance(&att);
			Assert::AreEqual(result, 0.0);
		}

		TEST_METHOD(TestDistanceAttributDouble2)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux AttributDouble
			retourne la valeur attendue
			*/

			AttributDouble att1("attribut1", 1.0);
			AttributDouble att2("attribut2", 2.0);
			double result1 = att1.distance(&att2);
			double result2 = att2.distance(&att1);
			Assert::AreEqual(result1, 1.0);
			Assert::AreEqual(result2, 1.0);
		}

		TEST_METHOD(TestDistanceAttributDouble3)
		{
			/*
			Ce test unitaire permet de vérifier que la méthode distance appliquée à deux AttributDouble
			distincts ayant des valeurs identiques retourne 0.0
			*/

			AttributDouble att1("attribut1", 1.0);
			AttributDouble att2("attribut2", 1.0);
			Assert::AreEqual(att1.distance(&att2), 0.0);
		}
	};
}