#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
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

  std::tuple<int, int> BFS(int source, int gatewayNode) {

    std::queue<int> queue;
    queue.push(source);

    while (!queue.empty()) {

      int current = queue.front();
      queue.pop();

      std::vector<int> &currentChilds = this->adjacencyVector[current];
      for (auto it = currentChilds.begin(); it != currentChilds.end();) {
        int childNode = currentChilds[*it];

        queue.push(childNode);
        if (childNode == gatewayNode) {

          it = currentChilds.erase(it);

          // cout << current << " " << linkNode;
          return std::make_tuple(current, childNode);

          queue = {};
          break;
        } else {
          ++it;
        }
      }
    }
    return std::make_tuple(0, 0);
  }
};
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main() {
  int n; // the total number of nodes in the level, including the gateways
  Graph graph(n);

  int l; // the number of links
  int e; // the number of exit gateways
  cin >> n >> l >> e;
  cin.ignore();
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

    const auto foundGateway =
        std::lower_bound(gatewayNodes.begin(), gatewayNodes.end(), si);

    auto nodesLinkToBlock = graph.BFS(si, *foundGateway);

    gatewayNodes.erase(foundGateway);
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    // Example: 0 1 are the indices of the nodes you wish to sever the link
    // between
    cout << std::get<0>(nodesLinkToBlock) << " "
         << std::get<1>(nodesLinkToBlock) << endl;
  }
}