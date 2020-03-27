#include "LinTabList.h"

LinTabList::LinTabList() : Head(nullptr), Amount(0)
{
}

LinTabList::~LinTabList()
{
	while ((Head != nullptr) && (Amount))
	{
		Link* p = Head;
		if (p->pNext != nullptr)
			Head = p->pNext;
		delete p;
		Amount--;
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

void LinTabList::Insert(Data d)
{
	if (Head == nullptr)
	{
		Head = new Link;
		Head->data.key = d.key;
		Head->data.Poly = d.Poly;
		Head->data.PolyString = d.PolyString;
		Head->pNext = nullptr;
		Amount++;

		return;
	}

	if (Find(d.key) != nullptr) throw 3;									// 3 means already here

	Link* p = new Link;
	p->data.key = d.key;
	p->data.Poly = d.Poly;
	p->data.PolyString = d.PolyString;
	p->pNext = Head;
	Head = p;
	Amount++;
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