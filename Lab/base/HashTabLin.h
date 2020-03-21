#include "BaseTable.h"

class HashTabLin : public BaseTable
{
  vector<Data> Table;
 public:
  HashTabLin();
  ~HashTabLin();
  
  Data* Find(int key);
  void Insert(Data data);
  void Delete(int key);

  int HashIt(Data data);
}
