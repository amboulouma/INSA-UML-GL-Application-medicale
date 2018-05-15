// AttributDouble.h
#include "Attribut.h"
#include "stdafx.h"


#ifndef AttributDouble_H
#define AttributDouble_H

using namespace std;

class AttributDouble : public Attribut
{
	private:
		double data;
	public:
		AttributDouble(string nom, double data);
		double distance(AttributDouble attributDouble);
};

#endif