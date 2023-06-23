#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Graph {
private:
  int vertices;

  std::vector<std::vector<int>> adjacencyVector;

public:
  Graph(int vertices) {
    this->vertices = vertices;
    this->adjacencyVector.resize(vertices);
  }

  void AddEdge(int v, int w) { this->adjacencyVector[v].push_back(w); }

  bool BFS(int source, int gatewayNode, std::tuple<int, int> &tuple) {

    std::vector<int> visitedNodes;

    std::list<int> queue;
    queue.push_back(source);
    while (!queue.empty()) {

      int current = queue.front();
      queue.pop_front();

      visitedNodes.push_back(current);

      std::vector<int> currentChilds = this->adjacencyVector[current];

      for (int i = 0; i < currentChilds.size(); ++i) {
        int childNode = currentChilds[i];

        // Did we already visit this node ?
        if (std::find(visitedNodes.begin(), visitedNodes.end(), childNode) !=
            visitedNodes.end()) {
          continue;
        }

        visitedNodes.push_back(childNode);

        if (childNode == gatewayNode) {

          tuple = {current, childNode};
          return true;
        }

        queue.push_back(childNode);
      }
    }

    // If we didn't find a link between gateway and a node
    // try checking from gateway to bobnet current node
    // because star validations has links from gateways.
    std::vector<int> gatewayChilds = this->adjacencyVector[gatewayNode];
    if (std::find(gatewayChilds.begin(), gatewayChilds.end(), source) !=
        gatewayChilds.end()) {
            
      tuple = {gatewayNode, source};
      return true;
    }

    // If we didn't find anything, just cut 0,1 because its always valid in all
    // cases.
    tuple = {0, 1};
    return false;
  };
};
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
  int n; // the total number of nodes in the level, including the gateways

  int l; // the number of links
  int e; // the number of exit gateways
  cin >> n >> l >> e;
  cin.ignore();

  Graph graph(n);

  for (int i = 0; i < l; i++) {
    int n1; // N1 and N2 defines a link between these nodes
    int n2;
    cin >> n1 >> n2;
    cin.ignore();

    graph.AddEdge(n1, n2);
  }

  std::vector<int> gatewayNodes;
  for (int i = 0; i < e; i++) {
    int ei; // the index of a gateway node
    cin >> ei;
    cin.ignore();

    gatewayNodes.push_back(ei);
  }

  // game loop
  while (1) {
    int si; // The index of the node on which the Bobnet agent is positioned
            // this turn
    cin >> si;
    cin.ignore();

    std::tuple<int, int> nodesLinkToBlock;
    for (const int gateway : gatewayNodes) {

      // If this method returns true, we found a valid link to block.
      // If not try every gateway because 4th case has multiple gateways.
      if (graph.BFS(si, gateway, nodesLinkToBlock)) {
        break;
      }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // Example: 0 1 are the indices of the nodes you wish to sever the link
    // between
    cout << std::get<0>(nodesLinkToBlock) << " "
         << std::get<1>(nodesLinkToBlock) << endl;
  }
}