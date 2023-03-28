#include <catch2/catch_test_macros.hpp>
#include <string>
using std::string;

// Finds the first character equal to one of the characters in the given character sequence.
// Using User-defined literals.
TEST_CASE("find_first_of") {
  string s1 = "abcdef";
  auto pos1 = s1.find_first_of("cbe");
  CHECK(pos1 == 1);

  auto pos2 = s1.find_first_of("cbe", 2); // start at index 2
  CHECK(pos2 == 2);
}
