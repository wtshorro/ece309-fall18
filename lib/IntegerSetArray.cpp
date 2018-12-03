#include <stdlib.h>
#include "IntegerSetArray.h"

namespace ece309{

bool IntegerSetArray::insert(int x){
  int i;
  for(i = 0; i < size; i++){
    if(array[i] == -1){
      array[i] = x;
      return true;
    }
  }
  return false;
}

bool IntegerSetArray::search(int x)const{
  if(empty()){
    return false;
  }
  for(int i = 0; i < size; i++){
    if(array[i]  == x){
      return true;
    }
  }
  return false;
}

void IntegerSetArray::remove(int x){
  if(empty()){
    return;
  }
  int i;
  for(i = 0; i < size; i++){
    if(array[i] == x){
      array[i] = -1;
      ShiftArray();
      break;
    }
  }
}
void IntegerSetArray::ShiftArray(){
  int i;
  for(i = 0; i < size-1; i++){
    array[i]=array[i+1];
  }
}
bool IntegerSetArray::empty()const{
  return array[0]==-1;
}
}
