#include <algorithm>
#include <vector>

// Runtime: 150 ms, faster than 65.37% of C++ online submissions for Maximum
// Length of Pair Chain.
// Memory Usage: 22.4 MB, less than 89.08% of C++ online submissions for Maximum
// Length of Pair Chain.

int findLongestChain(std::vector<std::vector<int>> &pairs) {
  std::sort(pairs.begin(), pairs.end(),
            [](const auto &p1, const auto &p2) { return p1[1] < p2[1]; });

  auto cnt = 1;
  auto prev = 0;
  for (auto i = 1u; i < pairs.size(); ++i) {
    if (pairs[prev][1] == pairs[i][0]) {
      continue;
      ;
    } else if (pairs[prev][1] > pairs[i][0]) {
      continue;
    } else {
      prev = i;
      ++cnt;
    }
  }
  return cnt;
}

int main(int argc, char **argv) {
  std::vector<std::vector<int>> pairs;
  for (auto i = 1; i < argc - 1; i += 2) {
    pairs.push_back({std::atoi(argv[i]), std::atoi(argv[i + 1])});
  }

  printf("findLongestChain(...)=%d\n", findLongestChain(pairs));
}