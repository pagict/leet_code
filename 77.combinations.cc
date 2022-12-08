#include <cstdio>
#include <vector>

#include "leetcode_common_struct.h"

// Runtime 46ms, beats 51.94%
// Memory 19MB, beats 25.2%

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<std::vector<int>>> dp_x;
  dp_x.reserve(k);

  dp_x.push_back(std::vector<std::vector<int>>());
  auto &dp_last = dp_x.back();
  for (auto i = 1; i < n + 1; ++i) {
    dp_last.push_back({i});
  }

  for (auto i = 1; i < k; ++i) {
    const auto &dp = dp_x.back();
    dp_x.push_back(std::vector<std::vector<int>>());
    auto &new_dp = dp_x.back();
    auto last = n - k + 1 + i;

    for (auto dpi : dp) {
      auto copy_vec = dpi;
      copy_vec.push_back(0);
      for (auto j = dpi.back() + 1; j <= last; ++j) {
        copy_vec.back() = j;
        new_dp.push_back(copy_vec);
      }
    }
  }
  return dp_x.back();
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "program <n> <k>");
    return -1;
  }
  int n = std::atoi(argv[1]);
  int k = std::atoi(argv[2]);
  auto combs = combine(n, k);
  for (const auto &vec : combs) {
    PrintVect(vec);
  }
}