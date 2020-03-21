#pragma once
#include "BaseTable.h"

struct Node
{
	Data data;
	Node* pNext;
};

class LinTabList : public BaseTable
{
	Node* Head;
public:
	LinTabList();
	~LinTabList();

	Data* Find(int key);
	void Insert(Data data);
	void Delete(int key);
};