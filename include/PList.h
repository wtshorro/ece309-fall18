//************************** PList.h ***************************//
namespace ece309{
class Object{
  private:
  public:
    virtual void print(){
      printf("Object!\n");
    }
};
class StringObject: public Object{
  private:
    char* str;
  public:
    StringObject(char* string):str(string){}
    void print(){
      printf("%s\n", str);
    }
};
class IntegerObject: public Object{
  private:
    int num;
  public:
    IntegerObject(int number):num(number){}
    void print(){
      printf("%d\n", num);
    }
};
class DoubleObject: public Object{
  private:
    double dbl;
  public:
    DoubleObject(double d):dbl(d){}
    void print(){
      printf("%f\n",dbl);
  }
};
class PList{
  private:
    class ListNode{
      private:
        Object* obj;
        ListNode* next;
        ListNode* prev;
      public:
        ListNode();
        ListNode(Object* o);
        void setNext(ListNode* node);
        void setPrev(ListNode* node);
        ListNode* getNext(void);
        ListNode* getPrev(void);
        void setObj(Object* o);
        Object* getObj(void);
    };
    ListNode* head;
    ListNode* tail;
  public:
    class Iterator {
      private:
        ListNode* current_node;
      public:
        Iterator(ListNode*);
        Object* getObj();
        void increment();
        void decrement();
        void print();
    };
    PList();
    PList(Object* o);
    Iterator begin();
    int length();
    bool empty();
    void push_back(Object*);
    bool remove_front(Object&);
    bool get(int n, Object*);
};
}

//************************** End PList.h ***************************//
