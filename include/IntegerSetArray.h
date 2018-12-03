#include "IntegerSet.h"
#include <stdlib.h>

namespace ece309{
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
  virtual bool insert(int);
  virtual bool search(int) const;
  virtual void remove(int);
  bool empty()const;
  ~IntegerSetArray(){
    free(array);
  }
};
}
