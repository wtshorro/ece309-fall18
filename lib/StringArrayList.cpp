#include <stdio.h>
#include <stdlib.h>

namespace ece309{
  
class StringArrayList {
private:
  char** list;
  int head;
  int tail;
  int size;
  void makeLonger();
  void shiftLeft();
public:
  StringArrayList();
  StringArrayList(char*, int);
  ~StringArrayList();
  void push_back(char*);
  int length();
  char* remove_front();
  char* get(int);
};
StringArrayList::StringArrayList(){
  size = 1;
  list = (char**)malloc(sizeof(char*)*size);
  int i;
  for(i = 0; i < size; i++){
    list[i] = NULL;
  }
  head = -1;
  tail = -1;
}
StringArrayList::StringArrayList(char* string, int init_size = 5){
  size = init_size;
  list = (char**)malloc(sizeof(char*)*size);
  list[0] = string;
  int i;
  for( i = 1; i < size; i++){
    list[i] = NULL;
  }
  head = 0;
  tail = 0;
}
void StringArrayList::push_back(char* string){
  if(tail == -1 || head == -1){
    list[0] = string;
    tail = 0;
    head = 0;
  }
  else if((tail +1) >= size){
    makeLonger();
    list[tail+1] = string;
    tail = tail + 1;
  }
  else{
    list[tail+1] = string;
    tail = tail + 1;
  }
}
void StringArrayList::makeLonger(){
  printf("calling makeLonger()\n");
  size += 2;
  char** temp = (char**)malloc(sizeof(char*)*(size));
  int i;
  for(i = 0; i <= tail; i++){
    temp[i] = list[i];
  }
  free(list);
  list = temp;
}
void StringArrayList::shiftLeft(){
  int i;
  for(i = 0; i < (tail - head); i++){
    list[i] = list[i+1];
  }
  list[tail] = NULL;
  tail = i-1;
  head = 0;
}
char* StringArrayList::remove_front(){
  if(head == -1 ){
    return NULL;
  }
  else if(head == tail){
    char* temp = list[head];
    list[head] = NULL;
    head = -1;
    tail = -1;
    return temp;
  }
  else{
    char* temp = list[head];
    shiftLeft();
    return temp;
  }
}
int StringArrayList::length(){
  if(head == -1){
    return 0;
  }
  else{
    return (tail - head + 1);
  }
}
char* StringArrayList::get(int n){
  if(size > n){
    if(list[n] != NULL){
      return list[n];
    }
    else{
      return NULL;
    }
  }
  else{
    return NULL;
  }
}
StringArrayList::~StringArrayList(){
  printf("Deleting List\n");
  free(list);
  head = -1;
  tail = -1;
}
}
int main(void){
  return 0;
}
// void printList(StringArrayList&);
// int main(void){
//   StringArrayList* list = new StringArrayList();
//   printf("Adding to List: string 1\n");
//   char* string = (char*)("string 1");
//   list->push_back(string);
//   printf("Adding to List: string 2\n");
//   string = (char*)("string 2");
//   list->push_back(string);
//   printf("Adding to List: string 3\n");
//   string = (char*)("string 3");
//   list->push_back(string);
//   printf("Adding to List: string 4\n");
//   string = (char*)("string 4");
//   list->push_back(string);
//   printList(*list);
//   printf("printing array index n = 2 : %s\n", list->get(2));
//   printf("removing head of list: %s\n", list->remove_front());
//   printList(*list);
//   delete(list);
//   printList(*list);
//   return 0;
// }
// void printList(StringArrayList& list){
//   int i;
//   int length = list.length();
//   printf("the current state of the list: \n");
//   printf("the List length is: %d\n", length);
//   for(i = 0; i < length; i++){
//     char* string = list.get(i);
//     printf("[%s]", string);
//     if(i+1 < length){
//       printf(", ");
//     }
//   }
//   printf("\n");
// }
