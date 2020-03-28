//#pragma once

#ifndef __ORDERED_LINE_TABLE_H__
#define __ORDERED_LINE_TABLE_H__

//#include <string>
//#include <iostream>
#include "BaseTable.h"

using namespace std;

class ordered_line_table : public BaseTable
{
	Data* Tab[1000];
	int size;
public:
	ordered_line_table()
	{
		for (int i = 0; i < 1000; i++)
			Tab[i] = nullptr;
		size = 0;
	}
	~ordered_line_table();
	Data* Find(string key);
	void Insert(Data data);
	void Delete(string key); // 
	void Print();
	int Compare(string k1, string k2);
};

#endif