#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Polynom.h"

struct Data
{
	std::string key;
	std::string PolyString;
	Polynom Poly;
};

class BaseTable
{
public:
	virtual Data* Find(string key) = 0;
	virtual void Insert(Data data) = 0;
	virtual void Delete(string key) = 0;
};
