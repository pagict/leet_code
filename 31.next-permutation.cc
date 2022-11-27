#include "leetcode_common_struct.h"
#include <algorithm>
#include <iterator>
#include <vector>

// Runtime: 12 ms, faster than 22.42% of C++ online submissions for Next
// Permutation. Memory Usage: 12.2 MB, less than 37.30% of C++ online
// submissions for Next Permutation.

void nextPermutation(std::vector<int> &nums) {
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
}

int main(int argc, char **argv) {
  std::vector<int> nums;
  for (auto i = 1u; i < argc; ++i) {
    nums.push_back(std::atoi(argv[i]));
  }
  std::sort(nums.begin(), nums.end());
  auto initial = nums;
  PrintVect(nums);
  do {
    nextPermutation(nums);
    PrintVect(nums);
  } while (nums != initial);
  //   nextPermutation(nums);
  //   PrintVect(nums);
}