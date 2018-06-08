#include "stdafx.h"

// Attribut.h
#include <string>

#ifndef Attribut_H
#define Attribut_H

using namespace std;

class Attribut
{
  protected:
	string nom;

  public:
	virtual double distance(Attribut *attribut) = 0;
};

#endif