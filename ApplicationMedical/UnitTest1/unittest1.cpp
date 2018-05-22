#include "stdafx.h"
#include "CppUnitTest.h"
#include "./../ApplicationMedical/Empreinte.h"
#include "./../ApplicationMedical/Attribut.h"
#include "./../ApplicationMedical/AttributString.h"
#include "./../ApplicationMedical/AttributDouble.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector <Attribut*> attributs(5);
			attributs.push_back(new AttributDouble("Att1", 0.5));
			attributs.push_back(new AttributString("Att2", "content"));
			attributs.push_back(new AttributDouble("Att3", 1.5));
			attributs.push_back(new AttributString("Att4", "content2"));
			attributs.push_back(new AttributDouble("Att5", 2.5));
			Empreinte e1(1, attributs);
			Assert::AreEqual(e1.distance(e1), 0.0);
		}

	};
}