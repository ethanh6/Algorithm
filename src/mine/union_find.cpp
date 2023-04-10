#include <catch2/catch_test_macros.hpp>
#include <vector>
using namespace std;

class DSU {
public:
  vector<int> root, size;

  explicit DSU(int sz) : root(sz), size(sz) {
    for (int i = 0; i < sz; ++i) {
      root[i] = i; // Initially each group is its own root
      size[i] = 1; // Intialize the size of all groups to 1
    }
  }

  // Finds the root of group x
  int findRoot(int x) {
    if (x == root[x])
      return x;

    // This is path compression
    root[x] = findRoot(root[x]);
    return root[x];
  }

  // Unite the group that contains "a" with the group that contains "b"
  void unionBySize(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    // If nodes a and b already belong to the same group, do nothing.
    if (rootA == rootB) 
      return;

    // Union by size: point the root of the smaller group to the root of the larger group.
    if (size[rootA] >= size[rootB]) {
      size[rootA] += size[rootB];
      root[rootB] = rootA;
    } else {
      size[rootB] += size[rootA];
      root[rootA] = rootB;
    }
  }
};
