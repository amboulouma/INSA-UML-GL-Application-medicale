// AttributDouble.h
#include "Attribut.h"
#include <string>

#ifndef AttributDouble_H
#define AttributDouble_H

using namespace std;

class AttributDouble : public Attribut
{
private:
	double data;
public:
	double distance(AttributDouble attributDouble);
};

#endif