#ifndef INTEGERSET_H
#define INTEGERSET_H

#include "List.h"
#include <math.h>

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   bool square_hash;
   int hash(int key) const {
     if(square_hash){
       int squaredKey = key*key;
       int r = ceil(log2(size));
       int extractedBits = squaredKey >> ((32-r)/2);
       extractedBits = extractedBits & (0xFFFFFFFF >> (32-r));
       return extractedBits % size;
     }
     else{
       return (key * 997) % size;
     }
   }

public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  const int empty_since_start = -2;
  const int empty_after_removal = -1;
public:
  class iterator{
  private:
    int* table;
    int size;
    int index;
    int probeDistance;
  public:
    iterator(int* hash_table, int table_size, int distance = 0){
      table = hash_table;
      index = -1;
      probeDistance = distance;
      size = table_size;
      for(int i = 0; i < size; i++){
        if(table[i]>=0){
          index = i;
          break;
        }
      }
    }
    bool end(){
      return index >= size;
    }
    void increment(){
      index++;
      while(!end()){
        if(table[index]<0){
          index++;
        }
        else{
          break;
        }
      }
    }
    int getInt(){
      return table[index];
    }
  };
   IntegerSetHT();
   IntegerSetHT(int htsize);
   IntegerSetHT(int htsize, int distance, bool square_hash);
   virtual bool insert(int) override;
   bool insert(int,int&);
   virtual bool search(int) const override;
   virtual void remove(int) override;
   void print(void);
   iterator begin(){
     return iterator(table,size,probeDistance);
   }

};

// Hash Table with Chaining
class IntegerSetHTChain : public IntegerSet {
protected:
  List *table;
public:
   IntegerSetHTChain(int htsize);
   virtual bool insert(int) override;
   bool insert(int,int&);
   virtual bool search(int) const override;
   virtual void remove(int) override;
};
#endif //INTEGERSET_H
