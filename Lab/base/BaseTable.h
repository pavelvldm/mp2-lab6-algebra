//#pragma once

#ifndef __BASE_TABLE_H__
#define __BASE_TABLE_H__

#include <iostream>
//#include <string>
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
	virtual Data* Find(std::string key) = 0;
	virtual void Insert(Data data) = 0;
	virtual void Delete(std::string key) = 0;
};

int HashIt(std::string key);

#endif