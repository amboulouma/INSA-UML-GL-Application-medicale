// AttributString.h
#include <string>
#include "Attribut.h"

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