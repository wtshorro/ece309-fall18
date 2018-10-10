#include "IntegerSet.h"
#include <stdlib.h>

class IntegerSetArray: public IntegerSet{
private:
  int* array;
  void ShiftArray();
public:
  IntegerSetArray(int size = 0):IntegerSet(size){
    array = (int*)malloc(sizeof(int)*size);
    int i;
    for(i = 0; i < size; i++){
      array[i] = -1;
    }
  }
  bool insert(int);
  bool search(int) const;
  void remove(int);
  bool empty()const;
  ~IntegerSetArray(){
    free(array);
  }
};
