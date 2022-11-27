#include <algorithm>
#include <vector>

#include "leetcode_common_struct.h"
using std::vector;

// Runtime: 5 ms, faster than 56.71% of C++ online submissions for Permutations.
// Memory Usage: 7.5 MB, less than 91.87% of C++ online submissions for
// Permutations.

vector<vector<int>> permute(vector<int> &nums) {
  vector<vector<int>> res;
  std::sort(nums.begin(), nums.end());
  do {
    res.push_back(nums);

    int i = nums.size() - 1;
    for (; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        int j = nums.size() - 1;
        for (; j >= i; --j) {
          if (nums[j] > nums[i - 1]) {
            break;
          }
        }

        std::swap(nums[i - 1], nums[j]);
        for (; j > i; --j) {
          if (nums[j] < nums[j - 1]) {
            break;
          }
          std::swap(nums[j - 1], nums[j]);
        }
        break;
      }
    }

    int j = nums.size() - 1;
    while (i < j) {
      std::swap(nums[i], nums[j]);
      ++i;
      --j;
    }
  } while (nums != res[0]);
  return res;
}

int main(int argc, char **argv) {
  vector<int> nums;
  for (auto i = 1; i < argc; ++i) {
    nums.push_back(std::atoi(argv[i]));
  }
  auto res = permute(nums);
  for (const auto &v : res) {
    PrintVect(v);
  }
}