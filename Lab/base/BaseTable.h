#pragma once
#include <iostream>
#include <vector>
#include <string>

struct Data
{
	int key;
        string Polynom;  
};

class BaseTable
{
public:
	virtual Data* Find(int key) = 0;
	virtual void Insert(Data data) = 0;
	virtual void Delete(int key) = 0;
};
