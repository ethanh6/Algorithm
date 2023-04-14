#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// remove a value from a vector.
// This is also called erase-remove idiom

TEST_CASE("erase remove ediom") {
  vector<int> v {1, 2, 3, 4, 5, 6};
  v.erase(std::remove(v.begin(), v.end(), 4), v.end());
  REQUIRE(v == vector<int>{1, 2, 3, 5, 6});
}
