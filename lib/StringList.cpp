#include <stdio.h>
#include <string.h>

class List {
private:
  class ListNode {
  private:
      char* text;
      ListNode* next;
  public:
      ListNode(){
        text = NULL;
        next = NULL;
      }
      ListNode(char* new_text){
        text = new_text;
        next = NULL;
      }
      ListNode* getNext(){
        return next;
      }
      void setNext(ListNode* node){
        next = node;
      }
      char* getText(){
        return text;
      }
  };
  ListNode* head;
  ListNode* tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        if(head != NULL){
            while(head->getNext() != NULL){
                ListNode* temp = head->getNext();
                printf("deleting %s from the list.\n", head->getText());
                delete head;
                head = temp;
            }
            printf("deleting %s from the list.\n", head->getText());
            delete head;
            head = NULL;
            tail = NULL;
        }
    }
    char* remove_front(){
        char* data = NULL;
        if(head != NULL){
            data = head->getText();
            ListNode* temp = head->getNext();
            printf("deleting %s from the list.\n", head->getText());
            if(head == tail){
              tail = temp;
            }
            delete head;
            head = temp;
        }
        return data;
    }
    int length(){
        int i = 1;
        if(head == NULL){
            return i;
        }
        else{
            ListNode* current_node = head;
            while(current_node->getNext() != tail){
              i++;
              current_node = current_node->getNext();
            }
            i++;
        }
        return i;
    }
    char* get(int n){
        if(head == NULL){
          return NULL;
        }
        else{
          int i;
          ListNode* temp;
          temp = head;
          for(i = 1; i <= n; i++){
            if(temp == tail){
              return NULL;
            }
          else{
              temp = temp->getNext();
            }
          }
            return temp->getText();
        }
    }
    void push_back(char* string){
        ListNode* nodeToAdd = new ListNode(string);
        if(head == NULL){
            head = nodeToAdd;
            tail = nodeToAdd;
        }
        else{
            tail->setNext(nodeToAdd);
            tail = nodeToAdd;
        }
    }
};

void printN(int , List*);
int main(void){
  List* a = new List();
  a->push_back("string 1");
  char* data = a->remove_front();
  printf("this is the data removed: %s\n", data);
  a->push_back("string 2");
  a->push_back("string 3");
  a->push_back("string 4");
  printN(0,a);
  printN(1,a);
  printN(2,a);
  printN(3,a);
  printN(4,a);
  int length = a->length();
  printf("the length of the list is %d \n", length);
  char* removed = a->remove_front();
  printf("the following string was just removed: %s\n", removed);
  printN(0,a);
  printN(1,a);
  printN(2,a);
}
void printN(int n, List *a){
  char* string;
  if(a->get(n) != NULL){
      string = a->get(n);
  }
  else{
      string = "there is no item at this index";
  }
  printf("this is the %d item in the list: %s\n",(n+1), string);
}
