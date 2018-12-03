//************************** Test Code ***************************//
#include<stdio.h>
#include "PList.h"

using namespace ece309;

int main(void){
  PList a;
  a.push_back(new StringObject((char*)"I'm a String"));
  a.push_back(new DoubleObject(14.52));
  a.push_back(new IntegerObject(22));

  PList::Iterator it = a.begin();
  it.print();
  it.decrement();
  it.print();
  it.decrement();
  it.print();
  it.decrement();
  it.print();
  it.increment();
  it.print();
  it.increment();
  it.print();
  it.increment();
  it.increment();
  it.print();

  return 0;
}
//************************** End Test Code ***************************//
