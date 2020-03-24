#include "LinTabList.h"

LinTabList::LinTabList() : Head(nullptr)
{
}

LinTabList::~LinTabList()
{
	while (Head != nullptr)
	{
		Link* p = Head;
		if (p->pNext != nullptr)
			Head = p->pNext;
		delete p;
	}
}

Data* LinTabList::Find(string k)
{
	if (Head == nullptr) return nullptr;

	Link* p = Head;

	if (k == p->data.key)
		return &(p->data);

	while (p->pNext != nullptr)
	{
		p = p->pNext;

		if (k == p->data.key)
			return &(p->data);
	}
	
	return nullptr;
}

void LinTabList::Insert(Data data)
{
	if (Head == nullptr)
	{
		Head = new Link;
		Head->data = data;
		Head->pNext = nullptr;

		return;
	}

	if (Find(data.key) != nullptr) throw 3;									// 3 means already here

	Link* p = new Link;
	p->data = data;
	p->pNext = Head;
	Head = p;
}

void LinTabList::Delete(string k)
{
	if (Head == nullptr) throw 1;											// 1 means empty

	Link* p = Head;

	if (k == p->data.key)
	{
		if (p->pNext != nullptr)
		{
			Head = p->pNext;
			delete p;
			return;
		}
		else
		{
			delete p;
			Head = nullptr;
			return;
		}
	}

	Link* pp;

	while (p->pNext != nullptr)
	{
		pp = p;
		p = p->pNext;

		if (k == p->data.key)
		{
			if (p->pNext != nullptr)
				pp->pNext = p->pNext;

			delete p;
			return;
		}
	}

	throw 2;																// 2 means lack of key
}