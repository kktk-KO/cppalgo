#include <benchmark/benchmark.h>

#include <cxxalgo/sort/bubble_sort.hpp>

#include <algorithm>
#include <chrono>
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

    auto start = std::chrono::high_resolution_clock::now();
    T()(v.begin(), v.end());
    auto end = std::chrono::high_resolution_clock::now();

    state.SetIterationTime(std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count());
  }
}

BENCHMARK_TEMPLATE(ascending_int, cxxalgo::sort::bubble_sort_fn)->DenseRange(1, 512, 32)->Range(1 << 11, 1 << 14)->UseManualTime();

BENCHMARK_MAIN()
