#pragma once
#include <iostream>

struct Data
{
	int key;
};

class BaseTable
{
public:
	virtual Data* Find(int key) = 0;
	virtual void Insert(Data data) = 0;
	virtual void Delete(int key) = 0;
};
