// AttributString.h
#include <string>
#include "Attribut.h"
#include "stdafx.h"

#ifndef AttributString_H
#define AttributString_H

using namespace std;

class AttributString: public Attribut
{
	private:

		string data;

	public:

		AttributString();

		AttributString(string nom, string data);

		~AttributString();

		double distance(AttributString attributString);
};

#endif