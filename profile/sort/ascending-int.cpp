#include <benchmark/benchmark.h>

#include <cxxalgo/sort/bubble_sort.hpp>

#include <algorithm>
#include <random>
#include <vector>

template <class T>
void ascending_int (benchmark::State & state) {
  std::vector<int> v;
  std::random_device device;
  std::mt19937 urng(device());

  while (state.KeepRunning()) {
    auto N = state.range(0);
    v.resize(N);
    for (int i = 0; i < N; ++i) {
      v[i] =i;
    }
    std::shuffle(v.begin(), v.end(), device);
  
    T()(v.begin(), v.end());
  }
}

BENCHMARK_TEMPLATE(ascending_int, cxxalgo::sort::bubble_sort_fn)->Range(1 << 0, 1 << 10);

BENCHMARK_MAIN()
