#pragma once
#include "BaseTable.h"

class HashTabLin : public BaseTable
{
    std::vector<Data> Table;
public:
    HashTabLin();
    ~HashTabLin();

    Data* Find(std::string key);
    void Insert(Data data);
    void Delete(std::string key);

    int HashIt(Data data);
};
