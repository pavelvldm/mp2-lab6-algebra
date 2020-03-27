//#pragma once

#ifndef __HASH_TABLE_ON_LIST_H__
#define __HASH_TABLE_ON_LIST_H__

//#include <string>
//#include <iostream>
#include "BaseTable.h"

using namespace std;

class hash_table_on_lists
{

public:
  Data* Find(int key);
  void Insert(Data data);
  void Delete(int key); // 
  void Print();
};

#endif