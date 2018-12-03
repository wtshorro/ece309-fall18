//************************** PList.cpp ***************************//

#include <stdio.h>
#include "PList.h"

namespace ece309{
//ListNode Definitions
PList::ListNode::ListNode(){
}
PList::ListNode::ListNode(Object* o){
  obj = o;
  next = NULL;
  prev = NULL;
}
void PList::ListNode::setNext(ListNode* node){
  next = node;
}
void PList::ListNode::setPrev(ListNode* node){
  prev = node;
}
PList::ListNode* PList::ListNode::getNext(void){
  return next;
}
PList::ListNode* PList::ListNode::getPrev(void){
  return prev;
}
void PList::ListNode::setObj(Object* o){
  obj = o;
}
Object* PList::ListNode::getObj(void){
  return obj;
}

//End ListNode Definitions

//Iterator definitions
PList::Iterator::Iterator(ListNode* head){
  current_node = head;
}
Object* PList::Iterator::getObj(){
  return current_node->getObj();
}
void PList::Iterator::increment(){
  if(current_node->getNext()!= NULL){
    current_node = current_node->getNext();
  }
}
void PList::Iterator::decrement() {
     if(current_node->getPrev()!=NULL){
       current_node = current_node->getPrev();
     }
  // if(current_node != head){
  //   ListNode* temp = head;
  //   while(temp->getNext()!= current_node){
  //     temp = temp->getNext();
  //   }
  //   current_node = temp;
  // }
}
void PList::Iterator::print(){
  current_node->getObj()->print();
}
//End Iterator Definitions


//PList definitions
PList::PList(){
  head = NULL;
  tail = NULL;
}
PList::PList(Object* o){
  ListNode* temp = new ListNode(o);
  head = temp;
  tail = temp;
}
PList::Iterator PList::begin(){
  return Iterator(head);
}
int PList::length(){
  int i = 0;
  ListNode* temp = head;
  while(temp!=NULL){
    i++;
    temp = temp->getNext();
  }
  return i;
}
bool PList::empty(){
  return head == NULL;
}
void PList::push_back(Object* o){
  ListNode* temp = new ListNode(o);
  if(empty()){
    head = temp;
    tail = temp;
  }
  else{
    temp->setPrev(tail);
    tail->setNext(temp);
    tail = temp;
    // temp->setNext(head);//code for pushing front
    // head = temp;
  }
}
bool PList::remove_front(Object& copy){
  if(!empty()){
    copy = *(head->getObj());
    ListNode* temp = head->getNext();
    delete head;
    head = temp;
    if(temp == NULL){
      tail = NULL;
    }
    return true;
  }
  return false;
}
bool PList::get(int n, Object* copy){
if(head == NULL){
  return false;
}
int i;
ListNode* temp = head;
for(i = 0; i < n; i++){
  if(temp->getNext() != NULL){
    temp = temp->getNext();
  }
}
copy = temp->getObj();
return true;
}
}

//End PList definitions


//************************** End PList.cpp ***************************//
