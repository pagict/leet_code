#include <algorithm>
#include <vector>

#include "leetcode_common_struct.h"

using std::vector;

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<std::vector<int>>> sums(
      target + 1, std::vector<std::vector<int>>());

  for (auto i = 0; i < candidates.size(); ++i) {
    if (candidates[i] > target) {
      continue;
    }
    int num = candidates[i];

    for (int j = target - num; j >= 0; --j) {
      if (sums[j].empty())
        continue;

      for (auto k = 0; k < sums[j].size(); ++k) {
        sums[j + num].push_back(sums[j][k]);
        sums[j + num].back().push_back(num);
      }
    }

    if (sums[num].empty() || sums[num][0].size() != 1) {
      sums[num].insert(sums[num].begin(), {num});
    }
  }
  return sums[target];
}

int main(int argc, char **argv) {
  int target = std::atoi(argv[1]);
  std::vector<int> candidates;
  for (auto i = 2; i < argc; ++i) {
    candidates.push_back(std::atoi(argv[i]));
  }
  auto ret = combinationSum2(candidates, target);

  printf("[\n");
  for (auto res : ret) {
    PrintVect(res);
  }
  printf("]\n");
}