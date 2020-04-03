//#pragma once

#ifndef __LINE_TABLE_H__
#define __LINE_TABLE_H__

#include "BaseTable.h"

class LineTable : public BaseTable
{
	Data* dat;
	int size;
	int capacity;
	void repacking();
public:
	LineTable() : BaseTable()
	{
		capacity = 1000;
		size = 0;
		dat = new Data[capacity];
	}
	void Delete(string key);
	void Insert(Data d);
	Data* Find(string key);
	void Print();
	~LineTable();
};
#endif
