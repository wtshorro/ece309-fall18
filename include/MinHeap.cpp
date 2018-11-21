#include <stdio.h>
#include <stdlib.h>
#include "MinHeap.h"

void MinHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index].weight < heapArray[parent_index].weight) {
      int tmp = heapArray[index].weight;
      int tmp_node = heapArray[index].node;
      heapArray[index].weight = heapArray[parent_index].weight;
      heapArray[index].node = heapArray[parent_index].node;
      heapArray[parent_index].weight = tmp;
      heapArray[parent_index].node = tmp_node;
      index = parent_index;
    } else
      return;
  }
}

void MinHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index].weight;
  int node = heapArray[index].node;
  while (child_index < size) {
    int max_val = val;
    int max_node = node;
    int max_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i].weight < max_val) {
        max_val = heapArray[i].weight;
        max_node = heapArray[i].node;
        max_index = i;
      }
    }
    if (max_val == val)
      return;
    heapArray[index].weight = max_val;
    heapArray[index].node = max_node;
    heapArray[max_index].weight = val;
    heapArray[max_index].node = node;
    index = max_index;
    child_index = index * 2 + 1;
  }
}

bool MinHeap::insert(int data, int w) {
  if (nextIndex < heapArraySize) {
    heapArray[nextIndex].node = data;
    heapArray[nextIndex].weight = w;
    percolate_up(nextIndex);
    nextIndex++;
    return true;
  } else {
    return false;
  }
}

bool MinHeap::remove(int &val) {
  if (nextIndex > 0) {
    val = heapArray[0].node;
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}
bool MinHeap::empty(){
  return nextIndex == 0;
}
