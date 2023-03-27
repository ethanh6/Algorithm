#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <sstream>
using std::vector;


// print 1d and 2d generic vector
template <typename T> void print_vector(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
  std::cout << std::endl;
}

template <typename T> void print_2d_vector(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print_vector<typename T::value_type>);
}

// testing
class CoutRedirector {
 public:
  CoutRedirector(std::streambuf* new_buffer)
      : old_buffer_(std::cout.rdbuf(new_buffer)) {}

  ~CoutRedirector() {
    std::cout.rdbuf(old_buffer_);
  }

 private:
  std::streambuf* old_buffer_;
};



TEST_CASE("Test cout", "[test cout]") {
  std::stringstream buffer;
  CoutRedirector redirector(buffer.rdbuf());

  vector<int> v {1, 2, 3};
  print_vector(v);

  REQUIRE(buffer.str() == "1, 2, 3, \n");
}
