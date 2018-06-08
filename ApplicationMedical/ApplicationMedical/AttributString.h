#include "stdafx.h"
// AttributString.h
#include <string>
#include "Attribut.h"

#ifndef AttributString_H
#define AttributString_H

using namespace std;

class AttributString : public Attribut
{
  private:
	string data;

  public:
	AttributString();

	AttributString(string nom, string data);

	~AttributString();

	string getData();

	double distance(Attribut *attribut);

	bool operator==(const Attribut &unAtt);
};

#endif