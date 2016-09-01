#pragma once

#include <algorithm>
#include <random>

namespace cxxalgo { namespace sort {

template <class Iterator, class Compare>
void bogo_sort (Iterator first, Iterator last, Compare const & comp) {
  auto size = std::distance(first, last);
  std::mt19937 urng;

  while (true) {
    bool flag = true;
    for (decltype(size) i = 1; i < size; ++i) {
      if (!comp(first[i - 1], first[i])) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return;
    }
    std::shuffle(first, last, urng);
  }
}

template <class Iterator>
void bogo_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  bogo_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

struct bogo_sort_fn {

  template <class Iterator, class Compare>
  void operator() (Iterator first, Iterator last, Compare const & comp) {
    bogo_sort(first, last, comp);
  }

  template <class Iterator>
  void operator() (Iterator first, Iterator last) {
    bogo_sort(first, last);
  }

};

}}
