#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>
using std::string;
using std::transform;
using std::vector;

TEST_CASE("std::transform") {
  vector<int> v{1, 2, 3};

  // when newVector has been initialized with size,
  SECTION("use newVector.begin()") {
    vector<int> plus_one(v.size());
    transform(v.cbegin(), v.cend(), plus_one.begin(),
              [&](const int &x) { return x + 1; });

    REQUIRE(plus_one == vector<int>{2, 3, 4});
  }

  // when target vector has been initialized
  SECTION("newVector not inintialized") {
    vector<int> plus_two;
    transform(v.cbegin(), v.cend(), back_inserter(plus_two),
              [&](const int &x) { return x + 2; });
    REQUIRE(plus_two == vector<int>{3, 4, 5});
  }
}

TEST_CASE("with custom modifier") {
  vector<string> v1{"a", "b", "c"};
  vector<string> v2{"x", "y", "z"};
  vector<string> result;

  auto comp = [&](const string &a, const string &b) {
    return a + b ;
  };

  transform(v1.cbegin(), v1.cend(), v2.cbegin(), back_inserter(result), comp);

  REQUIRE(result == vector<string>{"ax", "by", "cz"});
}
