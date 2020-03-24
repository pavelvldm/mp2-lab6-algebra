#pragma once
#include "BaseTable.h"

struct Link
{
	Data data;
	Link* pNext;
};

class LinTabList : public BaseTable
{
	Link* Head;
public:
	LinTabList();
	~LinTabList();

	Data* Find(string key);
	void Insert(Data data);
	void Delete(string key);
};