#include <stdio.h>
#include <stdlib.h>
#include <climits>
#include "IntegerSet.h"
#include "Queue.h"
#include "MinHeap.h"
#include "Graph.h"


bool doesPathExist(Graph &g, int *path, int length) {
  for (int i = 0; i < length - 1; i++) {
    if (!g.isAdjacent(path[i], path[i + 1]))
      return false;
  }
  return true;
}

void visit(int node) { printf("%d ", node); }

void BreadthFirstSearch(Graph &graph, int start) {
  IntegerSetHT discovered(1000);
  Queue frontier;
  frontier.push(start);
  discovered.insert(start);
  while (!frontier.empty()) {
    int node = frontier.peek();
    visit(node);
    List adjList = graph.getAdjacencyList(node);
    List::iterator it = adjList.begin();
    while (!it.end()) {
      int j = it.getItem();
      if (!discovered.search(j)) {
        frontier.push(j);
        discovered.insert(j);
      }
      it.increment();
    }
    frontier.pop();
  }
}

void DepthFirstSearch_helper(Graph &g, IntegerSet &visitedSet, int node) {
  if (!visitedSet.search(node)) {
    visit(node); // take action upon visit to node
    visitedSet.insert(node);
    List adjList = g.getAdjacencyList(node);
    for (List::iterator it = adjList.begin(); !it.end(); it.increment())
      DepthFirstSearch_helper(g, visitedSet, it.getItem());
  }
}

void DepthFirstSearch(Graph &g, int node) {
  IntegerSetHT ht(1000);
  DepthFirstSearch_helper(g, ht, node);
}
node_helper *ShortestPath(Graph &g, int startV) {

  int numNodes = g.getNumNodes();
  node_helper *nodesH = new node_helper[numNodes];

  nodesH[startV].distance = 0;
  MinHeap unvisitedHeap;
  for (int i = 0; i < numNodes; i++){

    if(i == 0){
      unvisitedHeap.insert(i, 0);
    }else{
      unvisitedHeap.insert(i, g.getWeight(startV,i));
    }
  }

  while (!unvisitedHeap.empty()) {
    int min_node;
    unvisitedHeap.remove(min_node);
    int min_distance = nodesH[min_node].distance;
    int currentV = min_node;

    List adjList = g.getAdjacencyList(currentV);
    for (List::iterator lit = adjList.begin(); !lit.end(); lit.increment()) {
      int toNode = lit.getItem();
      if (g.getWeight(currentV, toNode) + min_distance < nodesH[toNode].distance) {
        nodesH[toNode].distance = g.getWeight(currentV, toNode) + min_distance;
        nodesH[toNode].pred = currentV;
      }
    }
  }
  return nodesH;
}


int main() {

  WeightedDenseGraph wg(6);
  wg.addEdge(0, 1, 450);
  wg.addEdge(0, 3, 150);
  wg.addEdge(0, 2, 370);
  wg.addEdge(1, 3, 550);
  wg.addEdge(2, 4, 210);
  wg.addEdge(3, 4, 370);
  wg.addEdge(3, 5, 340);
  wg.addEdge(2, 5, 130);
  wg.addEdge(4, 5, 5);

  printf("\nwg DFS(0): ");
  DepthFirstSearch(wg, 0);
  printf("\n\n");

  node_helper *nodesH = ShortestPath(wg, 0);

  for (int j = 0; j < wg.getNumNodes(); j++) {
    printf("%d: dist=%d pred=%d \n", j, nodesH[j].distance, nodesH[j].pred);
  }

  return 0;
}
