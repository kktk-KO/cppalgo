#pragma once

#include <algorithm>

namespace cxxalgo { namespace sort {

template <class Iterator, class Compare>
void bogo_sort (Iterator first, Iterator last, Compare const & comp) {
  auto size = std::distance(first, last);

  while (true) {
    bool flag = true;
    for (decltype(size) i = 1; i < size; ++i) {
      if (comp(first[i - 1], first[i])) {
        break;
        flag = false;
      }
    }
    if (flag) {
      return;
    }
    std::shuffle(first, last);
  }
}

template <class Iterator>
void bogo_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  bogo_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

}}
