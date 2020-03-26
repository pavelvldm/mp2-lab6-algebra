#include "HashTabLin.h"
#include "Polynom.h"

int HashIt(std::string key)
{
	int Hash = 0;

	for (unsigned int i = 0; i < key.size(); i++)
		Hash += (int)key[i];

	Hash *= key.size();
	return Hash % 1000;
}

HashTabLin::~HashTabLin()
{
	for (int i = 0; i < 1000; i++)
		if (Tab[i] != nullptr)
			delete Tab[i];
}

Data* HashTabLin::Find(std::string key)
{
	int SearchHash = HashIt(key);

	if (Tab[SearchHash] == nullptr)
	{
		for (int i = 0; i < 10; i++)
		{
			SearchHash = (SearchHash + 7) % 1000;
			if (Tab[SearchHash] != nullptr)
				if (Tab[SearchHash]->key == key)
					return Tab[SearchHash];
		}

		return nullptr;
	}
	else
	{
		if (Tab[SearchHash]->key == key)
			return Tab[SearchHash];
		else
		{
			for (int i = 0; i < 10; i++)
			{
				SearchHash = (SearchHash + 7) % 1000;
				if (Tab[SearchHash] != nullptr)
					if (Tab[SearchHash]->key == key)
						return Tab[SearchHash];
			}

			return nullptr;
		}
	}
}

void HashTabLin::Insert(Data data)
{
	if (Find(data.key) != nullptr)
		throw 3;
	int InsertHash = HashIt(data.key);

	if (Tab[InsertHash] == nullptr)
	{
		Tab[InsertHash] = new Data;
		Tab[InsertHash]->key = data.key;
		Tab[InsertHash]->PolyString = data.PolyString;
		Tab[InsertHash]->Poly = data.Poly;

		return;
	}
	else
	{
		if (Tab[InsertHash]->PolyString == data.PolyString)
			throw 3;
		for (int i = 0; i < 10; i++)
		{
			InsertHash = (InsertHash + 7) % 1000;

			if (Tab[InsertHash] == nullptr)
			{
				Tab[InsertHash] = new Data;
				Tab[InsertHash]->key = data.key;
				Tab[InsertHash]->PolyString = data.PolyString;
				Tab[InsertHash]->Poly = data.Poly;

				return;
			}
			else
				if (Tab[InsertHash]->PolyString == data.PolyString)
					throw 3;
		}

		throw 5;																// ��� �����
	}
}

void HashTabLin::Delete(std::string key)
{
	if (Find(key) == nullptr) throw 1;
	Data* p = Find(key);
	int DeleteHash = HashIt(p->key);
	delete Tab[DeleteHash];
	Tab[DeleteHash] = nullptr;
}