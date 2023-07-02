#include <catch2/catch_test_macros.hpp>
#include <string>
using std::string;

TEST_CASE("substr - starting position and length") {
  string s = "abcdef";
  int start_pos = 1;
  int len = 3;
  CHECK(s.substr(start_pos, len) == string("bcd"));
}

TEST_CASE("substr - python-like string slicing") {
  // Note: how to iterate through possible substrings
  // s.substr(l, r - l) is identical to
  // s[l:r] in python. So, r is non-inclusive.
  //
  string s = "abcdef";
  int l = 1;
  int r = 5;

  // this is like s[l:r] in python
  CHECK(s.substr(l, r - l) == string("bcde"));
}
