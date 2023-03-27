#include <catch2/catch_test_macros.hpp>
#include <vector>
using std::transform;
using std::vector;

TEST_CASE("test") {
  REQUIRE(true);
}

TEST_CASE("std::transform") {
  vector<int> v{1, 2, 3};

  // when newVector has been initialized with size,
  // use newVector.begin()
  vector<int> plus_one(v.size());
  transform(v.cbegin(), v.cend(), plus_one.begin(),
            [&](const int &x) { return x + 1; });

  REQUIRE(plus_one == vector<int>{2, 3, 4});
}


TEST_CASE("std::transform") {
  vector<int> v{1, 2, 3};

  // when newVector has been initialized with size,
  // use newVector.begin()
  vector<int> plus_two(v.size());
  transform(v.cbegin(), v.cend(), plus_two.begin(),
            [&](const int &x) { return x + 2; });

  REQUIRE(plus_two == vector<int>{3, 4, 5});
}
