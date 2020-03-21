#include "LinTabList.h"

LinTabList::LinTabList() : Head(nullptr)
{
}

LinTabList::~LinTabList()
{
	while (Head != nullptr)
	{
		Node* p = Head;
		if (p->pNext != nullptr)
			Head = p->pNext;
		delete p;
	}
}

Data* LinTabList::Find(int k)
{
	if (Head == nullptr) return nullptr;

	Node* p = Head;

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
		Head = new Node;
		Head->data = data;
		Head->pNext = nullptr;

		return;
	}

	if (Find(data.key) != nullptr) throw 3;									// 3 means already here

	Node* p = new Node;
	p->data = data;
	p->pNext = Head;
	Head = p;
}

void LinTabList::Delete(int k)
{
	if (Head == nullptr) throw 1;											// 1 means empty

	Node* p = Head;

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

	Node* pp;

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