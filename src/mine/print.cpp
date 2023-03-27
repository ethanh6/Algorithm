#include "../leetcode.hpp"

template <typename T> void print_vector(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, ", "));
  std::cout << std::endl;
}

template <typename T> void print_2d_vector(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print_vector<typename T::value_type>);
}
