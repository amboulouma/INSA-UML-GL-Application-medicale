#include "stdafx.h"

// AttributDouble.h
#include "Attribut.h"

#ifndef AttributDouble_H
#define AttributDouble_H

using namespace std;

class AttributDouble : public Attribut
{
  private:
	double data;

  public:
	AttributDouble();

	AttributDouble(string nom, double data);

	~AttributDouble();

	double getData();

	double distance(Attribut *attribut);

	bool operator==(const Attribut &unAtt);
};

#endif