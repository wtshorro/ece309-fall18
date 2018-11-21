#include <stdio.h>
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
