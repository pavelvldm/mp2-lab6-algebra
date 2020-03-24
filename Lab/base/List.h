#pragma once

template<typename T>
struct Node
{
	T data;
	int degr;
	Node *pNext;

	Node()
	{
		this->data = 0;
		this->degr = 0;
		this->pNext = nullptr;
	}

	Node(T dataOut, int dOut, Node *pN = nullptr)
	{
		this->data = dataOut;
		this->degr = dOut;
		this->pNext = pN;
	}
};

template<typename T>
class List
{
	Node<T> *Head;
	int Amount;

public:
	List();
	List(const List<T> &listOut);
	~List();

	void push_back(const T &val, const int &d = 0);
	void pop_front();

	T& operator[](const int ind);
	int GetAmount() { return Amount; }
	void SetAmount(const int &nA) { Amount = nA; }
	unsigned int GetDegree(const int ind);
	Node<T>* GetHead() { return Head; }

	// возвращает адрес элемента по индексу
	Node<T>* FindElem(const int &ind)
	{
		if ((ind < 0) || (ind > Amount - 1))
			throw std::exception("Wrong ind");

		int i = 0;
		Node<T> *p = Head;

		if (p != nullptr)
		{
			if (ind == 0)
				return p;

			while ((p->pNext != nullptr) && (i != ind))
			{
				p = p->pNext;
				i++;
			}
		}

		return p;
	}

	Node<T>* FindDegr(const int &d)
	{
		if ((d < 0) || (d > 999))
			throw std::exception("Wrong d");

		Node<T> *p = Head;

		if (p != nullptr)
		{
			if (p->degr == d)
				return p;

			while ((p->pNext != nullptr) && (p->degr != d))
				p = p->pNext;

			if (p->degr != d)
				return nullptr;
		}

		return p;
	}

	List<T>& operator=(const List<T> &listOut);
	bool operator==(const List<T> &listOut) const;
	bool operator!=(const List<T> &listOut) const;
	Node<T>* DelELem(Node<T> *p);

	void Sort();
};

