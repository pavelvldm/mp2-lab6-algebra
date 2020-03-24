#include "List.h"

template<typename T>
List<T>::List() : Head(nullptr), Amount(0)
{
}

template<typename T>
List<T>::List(const List<T> &listOut)
{
	Amount = 0;
	Head = nullptr;

	if (listOut.Head != nullptr)
	{
		Node<T> *p = listOut.Head;

		push_back(p->data, p->degr);

		while (p->pNext != nullptr)
		{
			p = p->pNext;
			push_back(p->data, p->degr);
		}
	}
}

template<typename T>
List<T>::~List()
{
	if (Head != nullptr)
	{
		while (Head->pNext != nullptr)
		{
			Node<T> *p = Head;
			Head = Head->pNext;
			delete p;
		}

		Node<T> *p = Head;
		delete p;

		Amount = 0;
	}
}

template<typename T>
void List<T>::push_back(const T &val, const int &d = 0)
{
	if (Head == nullptr)
	{
		Head = new Node<T>;
		Head->data = val;
		Head->degr = d;

		Amount++;
	}
	else
	{
		Node<T> *p = this->Head;

		while (p->pNext != nullptr)
			p = p->pNext;

		p->pNext = new Node<T>;
		p->pNext->data = val;
		p->pNext->degr = d;

		Amount++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	if (Head != nullptr)
	{
		Node<T> *p = Head;
		Head = Head->pNext;
		delete p;
		Amount--;
	}
	else
		throw std::exception("void");
}

template<typename T>
T& List<T>::operator[](const int ind)
{
	if ((ind < 0) || (ind > Amount - 1))
		throw std::exception("Wrong ind");

	int i = 0;
	Node<T> *p = Head;

	if (ind == 0)
		return p->data;

	while ((p->pNext != nullptr) && (i != ind))
	{
		p = p->pNext;
		i++;
	}

	return p->data;
}

template<typename T>
unsigned int List<T>::GetDegree(const int ind)
{
	if ((ind < 0) || (ind > Amount - 1))
		throw std::exception("Wrong ind");

	int i = 0;
	Node<T> *p = Head;

	if (ind == 0)
		return p->degr;

	while ((p->pNext != nullptr) && (i != ind))
	{
		p = p->pNext;
		i++;
	}

	return p->degr;
}

template<typename T>
List<T>& List<T>::operator=(const List<T> &listOut)
{
	if (this != &listOut)
	{
		if (Head != nullptr)
		{
			while (Head->pNext != nullptr)
			{
				Node<T> *p = Head;
				Head = Head->pNext;
				delete p;
				Amount--;
			}

			Node<T> *p = Head;
			delete p;
			Amount--;
			Head = nullptr;
		}

		Node<T> *p = listOut.Head;
		
		if (p != nullptr)
		{
			push_back(p->data, p->degr);

			while (p->pNext != nullptr)
			{
				p = p->pNext;
				push_back(p->data, p->degr);
			}
		}
	}

	return *this;
}

template<typename T>
bool List<T>::operator==(const List<T> &listOut) const
{
	if (Amount != listOut.Amount)
		return false;

	if ((Head != nullptr) && (listOut.Head != nullptr))
	{
		Node<T> *p1 = Head;
		Node<T> *p2 = listOut.Head;

		if ((p1->data != p2->data) && (p1->degr != p2->degr))
			return false;

		while ((p1->pNext != nullptr) && (p2->pNext != nullptr))
		{
			p1 = p1->pNext;
			p2 = p2->pNext;

			if ((p1->data != p2->data) && (p1->degr != p2->degr))
				return false;
		}

		return true;
	}

	return true;
}

template<typename T>
bool List<T>::operator!=(const List<T> &listOut) const
{
	return !(*this == listOut);
}

template<typename T>
Node<T>* List<T>::DelELem(Node<T> *p)
{
	if (p == Head)
	{
		if (p->pNext != nullptr)
		{
			Head = p->pNext;
			delete p;
			Amount--;
			return Head;
		}
		else
		{
			delete p;
			Amount--;
			return nullptr;
		}
	}

	Node<T> *cur = Head;

	while (cur->pNext != p)
		cur = cur->pNext;

	if (p->pNext != nullptr)
	{
		cur->pNext = p->pNext;
		delete p;
		Amount--;
		return cur;
	}
	else
	{
		cur->pNext = nullptr;
		delete p;
		Amount--;
		return cur;
	}
}

template<typename T>
void List<T>::Sort()
{
	if (Head == nullptr) return;
	if (Head->pNext == nullptr) return;

	for (int i = 1; i < Amount; i++)
	{
		Node<T> *Current = FindElem(i);
		int j = i - 1;

		while ((j > -1) && (Current->degr < GetDegree(j)))
		{
			Node<T> *tmp, *p, *pp, *pr;

			if (j > 0)
			{
				p = FindElem(j);
				pr = FindElem(j - 1);
				pp = Current;

				pr->pNext = pp;
				tmp = pp->pNext;
				pp->pNext = p;
				p->pNext = tmp;

				j--;
			}
			else
			{
				p = FindElem(j);
				pp = Current;

				tmp = pp->pNext;
				pp->pNext = p;
				p->pNext = tmp;

				j--;
			}
		}

		if (Current->degr < Head->degr)
			Head = Current;
	}
}