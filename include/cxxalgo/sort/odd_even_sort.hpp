#pragma once

#include <algorithm>

namespace cxxalgro { namespace sort {

template <class Iterator, class Compare>
void odd_even_sort (Iterator first, Iterator last, Compare const & comp) {
  auto size = std::distance(first, last);

  bool flag = true;
  while (flag) {
    flag = false;
    for (decltype(size) i = 0; i < size - 1; i += 2) {
      if (!comp(first[i], first[i + 1])) {
        std::swap(first[i], first[i + 1]);
        flag = true;
      }
    }
    for (decltype(size) i = 1; i < size - 1; i += 2) {
      if (!comp(first[i], first[i + 1])) {
        std::swap(first[i], first[i + 1]);
        flag = true;
      }
    }
  }
}

template <class Iterator>
void odd_even_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  odd_even_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

}}
