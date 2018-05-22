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
		double distance(AttributString attributString);
};

#endif