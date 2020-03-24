#pragma once

#include <string>
#include <iostream>

using namespace std;

class ordered_line_table
{

public:

  Data* Find(int key);
  void Insert(Data data);
  void Delete(int key); // 
  void Print();
};