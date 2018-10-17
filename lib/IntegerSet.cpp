#include "IntegerSet.h"
#include <stdio.h>



// can only hold positive integers
IntegerSetHT::IntegerSetHT():IntegerSet(100){
  probeDistance = 20;
  table = new int[size];
  for(int i=0; i<size; i++)
     table[i] = empty_since_start;  // -1 means empty
}
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}
IntegerSetHT::IntegerSetHT(int htsize, int distance, bool hash_type):IntegerSet(htsize){
  probeDistance = distance;
  table = new int[size];
  for(int i=0; i<size; i++)
  table[i] = empty_since_start;
  square_hash = hash_type;
}
bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     return true;
   }
   index = (index+1) % size;
  }
  // otherwise give up
   return false;
}
bool IntegerSetHT::insert(int data, int& collision)
{
  int index = hash(data);
  int bucketsProbed = 0;
  //printf("trying to insert: %d\n", data);
  //printf("First index = %d\n", index);
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     //printf("inserting at index: %d\n", index);
     return true;
   }else{
     collision++;
     index = (index+1) % size;
     //printf("index was changed to %d\n", index);
   }
  }
  // otherwise give up
   return false;
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) ;
  }

  // data can only be in one location, check it
  return false;
}
void IntegerSetHT::print(){
  for(int i = 0; i < size; i++){
    printf("%d, " , table[i]);
  }
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}

IntegerSetHTChain::IntegerSetHTChain(int htsize)
:IntegerSet(htsize)
{
  square_hash = false;
  table = new List[size];
}

bool IntegerSetHTChain::insert(int data, int& collisons)
{
  List::iterator it;
  table[hash(data)].insertAfter(it,data);
  return true;
}

bool IntegerSetHTChain::search(int data) const
{
   List::iterator it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data)
        return true;
     it.increment();
   }
   return false;
}

void IntegerSetHTChain::remove(int data)
{
   List::iterator prev,it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data) {
        table[hash(data)].removeAfter(prev);
        return;
     }
     prev = it;
     it.increment();
   }
}
