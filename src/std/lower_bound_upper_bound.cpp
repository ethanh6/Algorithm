#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>

using std::cout, std::endl;
using std::lower_bound, std::upper_bound;
using std::vector;
using std::distance;

TEST_CASE("lower_bound and upper_bound") {

  const vector<int> data{1, 2, 2, 2, 3, 3, 3};

  auto lb = lower_bound(data.begin(), data.end(), 2);
  auto ub = upper_bound(data.begin(), data.end(), 2);

  REQUIRE(1 == distance(data.cbegin(), lb));
  REQUIRE(4 == distance(data.cbegin(), ub));
}


/*

value a a a b b b c c c
index 0 1 2 3 4 5 6 7 8
bound       l     u

l: lower_bound of b
u: upper_bound of b


reference:
https://stackoverflow.com/questions/41958581/difference-between-upper-bound-and-lower-bound-in-stl
      //
 * */
