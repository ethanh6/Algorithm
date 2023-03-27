#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
using std::vector;

template <typename T> void print_vector(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
  std::cout << std::endl;
}

template <typename T> void print_2d_vector(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print_vector<typename T::value_type>);
}

TEST_CASE("test") {
  vector<int> v{1, 2, 3};
  print_vector(v);
  REQUIRE(true);
}
