namespace ece309{
class MinHeap {
private:
  class V {
    public:
      int weight;
      int node;
      V(int n,int w){
        weight = w;
        node = n;
      }
      V& operator=(V &rhs){
        weight = rhs.weight;
        node = rhs.node;
        return *this;
      }
  };
  V *heapArray;    // this is the maxheap
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry

protected:
  void percolate_up(int);
  void percolate_down(int, int);
public:

  MinHeap(int size = 100) : heapArraySize(size) {
    heapArray = (V*)malloc(sizeof(V) * size);
    for (int i = 0; i < size; i++){
      heapArray[i].weight = 0;
      heapArray[i].node = 0;
    }
    nextIndex = 0;
  }

  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("%d ", heapArray[i].weight);
    }
    printf("\n");
  }

  bool insert(int n, int w);
  bool empty();
  bool remove(int &); // remove the max value
};
}
