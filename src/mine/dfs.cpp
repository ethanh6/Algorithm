#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Graph class
class Graph {
public:
  int V;                   // number of vertices
  vector<vector<int>> adj; // adjacency list

  vector<int> result;

  Graph(int v) {
    V = v;
    adj.resize(v);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // if the graph is undirected
  }

  void dfs(Graph &graph, int start) {
    vector<bool> visited(graph.V, false); // to keep track of visited nodes
    stack<int> stk;

    stk.push(start); // push the starting node to the stack

    while (!stk.empty()) {
      int u = stk.top();
      stk.pop();

      // skip any visited nodes
      if (!visited[u]) {
        visited[u] = true;

        // process the node
        result.push_back(u);

        // push all neighbors to the stack
        for (int v : graph.adj[u])
            stk.push(v);
      }
    }
  }
};


TEST_CASE("dfs") {
  Graph graph(5);
  graph.addEdge(0, 1);
  graph.addEdge(0, 2);
  graph.addEdge(1, 2);
  graph.addEdge(2, 3);
  graph.addEdge(3, 4);
  graph.dfs(graph, 0);
  REQUIRE(graph.result == vector<int>{0, 2, 3, 4, 1});
}
