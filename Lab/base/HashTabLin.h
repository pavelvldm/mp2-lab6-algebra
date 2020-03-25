#pragma once
#include "BaseTable.h"

class HashTabLin : public BaseTable
{
    Data* Tab[1000];
public:
    HashTabLin()
    {
        for (int i = 0; i < 1000; i++)
            Tab[i] = nullptr;
    }
    ~HashTabLin();

    Data* Find(std::string key);
    void Insert(Data data);
    void Delete(std::string key);

    friend int HashIt(std::string key);
};
