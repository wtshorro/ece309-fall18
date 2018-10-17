#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IntegerSet.h"
int main()
{
  IntegerSetHT* probe_hash = new IntegerSetHT(1000,20,false);
  srand(time(NULL));
	int r = 0;
  int i = 0;
  int total_bucket_collisions = 0;
  int prev_bucket_collision = 0;
  int inserts_with_collisions = 0;
  int failures = 0;
  while(i < 500){
    r = rand()%100000;
    if(!(probe_hash->insert(r, total_bucket_collisions))){
      failures++;
    }

    if(total_bucket_collisions > prev_bucket_collision){
      inserts_with_collisions++;
    }

    prev_bucket_collision = total_bucket_collisions;
    i++;
  }
  printf("There were %d collisions and %d failures when trying to insert %d items\n", inserts_with_collisions, failures, i);

  IntegerSetHT* probe_mid_square_hash = new IntegerSetHT(1000,20,true);
  r = 0;
  i = 0;
  total_bucket_collisions = 0;
  prev_bucket_collision = 0;
  inserts_with_collisions = 0;
  failures = 0;
  while(i < 500){
    r = rand()%100000;
    if(!(probe_mid_square_hash->insert(r, total_bucket_collisions))){
      failures++;
    }

    if(total_bucket_collisions > prev_bucket_collision){
      inserts_with_collisions++;
    }

    prev_bucket_collision = total_bucket_collisions;
    i++;
  }
  printf("There were %d collisions and %d failures when trying to insert %d items\n", inserts_with_collisions, failures, i);


  IntegerSetHT set;
  r = 0;
  i = 0;
  total_bucket_collisions = 0;
  prev_bucket_collision = 0;
  inserts_with_collisions = 0;
  set.insert(5,total_bucket_collisions);
  set.insert(99,total_bucket_collisions);
  set.insert(0,total_bucket_collisions);

  IntegerSetHT::iterator sit = set.begin();
  while(!sit.end())
  {
     printf("%d ", sit.getInt());
     sit.increment();
  }

  return 0;
}
