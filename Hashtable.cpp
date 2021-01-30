// HashTable.cpp
#include <vector>
#include "LinkedList.cpp"

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;
  int hashfunction (string hashitem) {
    const int p = 67;
    const int m = table.size();
    long long hashValue = 0;
    long long pPower = 1;
    for (char c : hashitem) {
        hashValue = (hashValue + ((int)c) * pPower) % m;
        pPower = (pPower * p) % m;
    }
    //std::cout << hashitem << ": " << hashValue << endl;
    return (int)hashValue;
  }
 public:
  HashTable (int size) {
    table.resize (size); // resize vector to support size elements.
  }
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }
  int size() {
    return table.size();
  }
  void insert (T newItem) {
    int index = hashfunction(newItem);
    table[index].insertFront(newItem);
  }
  bool retrieve (T & target) {
    int index = hashfunction(target);
    return table[index].find(target);
  }
  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
  void insertLinearProbing(T newItem){
    int index = hashfunction(newItem);
    if(!table[index].isEmpty()){
      bool occupied = true;
      while(occupied){
        if(index!=size()-1)
          index++;
        else
          index = 0;
        if (table[index].isEmpty())
            occupied = false;
      }
    }
    table[index].insertFront(newItem);
  }
  bool retrieveLinearProbing(T & target){
    int index = hashfunction(target);
    bool found = false;
    for(int i=0;i<table.size();i++){
      found = table[index].find(target);
      if (found) break;
      if(index==table.size()-1)
        index=0;
      else index++;
    }
    return found;
  }
};
