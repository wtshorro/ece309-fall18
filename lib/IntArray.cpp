#include "IntArray.h"
#include <stdlib.h>

#define ASCII_HIGH  (255)
#define ASCII_LOW   (0)
#define ASCII_SPACE (32)
#define ASCII_NULL  (0)

namespace ece309{
IntArray::IntArray(int size, int val = 0):length(size){
  array = new int[length];
  for(int i = 0; i < length; i++){
    array[i] = val;
  }
}

IntArray::IntArray(const char* str){
  int le = 0;
  while(str[le] != '\0'){
    le++;
  }
  length = le;
  array = new int[length];
  for(le = 0; le < length; le++){
    array[le] = str[le];
  }
}
int& IntArray::operator[](int index){
  return array[index];
}

IntArray& IntArray::operator+=(const IntArray &rhs){
  int le = length;
  if(rhs.length  < length){
    le = rhs.length;
  }
  for(int i = 0; i < le; i++){
    array[i] += rhs[i];
  }
  return *this;
}

IntArray IntArray::operator+(const IntArray &rhs) const{
  int le = length;
  if(length > rhs.length){
    le = rhs.length;
  }
  IntArray* temp = new IntArray(length);
  for(int i = 0; i < le; i++){
    if(i < le){
      temp->array[i] = array[i] + rhs.array[i];
    }
    else{
      temp->array[i] = array[i];
    }
  }
  return *temp;
}

IntArray IntArray::operator-(const IntArray &rhs) const{
  int le = length;
  if(length > rhs.length){
    le = rhs.length;
  }
  IntArray* temp = new IntArray(length);
  for(int i = 0; i < le; i++){
    if(i < le){
      temp->array[i] = array[i] - rhs.array[i];
    }
    else{
      temp->array[i] = array[i];
    }
  }
  return *temp;
}

IntArray IntArray::operator*(int x) const{
  IntArray* temp = new IntArray(length);
  for(int i = 0; i < length; i++){
    temp->array[i] = array[i]*x;
  }
  return *temp;
}

IntArray IntArray::operator/(int x) const{
  IntArray* temp = new IntArray(length);
  for(int i = 0; i < length; i++){
    temp->array[i] = array[i]/x;
  }
  return *temp;
}

IntArray IntArray::operator>>(int count) const{
  int i = 0;
  int temp_head = array[0];
  IntArray* temp = new IntArray(length);
  for(int j = 0; j < length; j++){
    temp->array[j] = array[j];
  }
  while(i<count){
    for(int j = 0; j < temp->length - 1; j++){
      temp->array[j] = temp->array[j+1];
    }
    temp->array[length-1] = temp_head;
    temp_head = temp->array[0];
    i++;
  }
  return *temp;
}
IntArray IntArray::operator<<(int count) const{
  int i = 0;
  int temp_tail = array[length-1];
  IntArray* temp = new IntArray(length);
  for(int j = 0; j < temp->length; j++){
    temp->array[j] = array[j];
  }
  while(i<count){
    for(int j = length - 1; j > 0; j--){
      temp->array[j] = temp->array[j-1];
    }
    temp->array[0] = temp_tail;
    temp_tail = temp->array[temp->length];
    i++;
  }
  return *temp;
}

IntArray::operator char*() const{
  int str_length = length;
  if(array[length-1] != 0){
    str_length++;
  }
  char* temp = (char*)malloc(sizeof(char)*str_length);
  for(int i = 0; i < length;i++){
    if(array[i] > ASCII_HIGH || array[i] < ASCII_LOW){
      temp[i] = ASCII_SPACE;
    }else{
      temp[i] = array[i];
    }
  }
  if(str_length != length){
    temp[str_length-1] = ASCII_NULL;
  }
  return temp;
}

IntArray::operator int() const{
  int avg = 0;
  for(int i = 0; i < length; i++){
    avg += array[i];
  }
  avg = avg / length;
  return avg;
}

int IntArray::get(int index){
  return array[index];
}
void IntArray::set(int index, int val){
  array[index] = val;
}
int IntArray::getLength(){
  return length;
}
}
