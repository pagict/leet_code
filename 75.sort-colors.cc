#include "leetcode_common_struct.h"
#include <string>
#include <vector>
using std::vector;

// Runtime 7ms, beats 16.95%
// Memory 8.3MB, beats 71.33%

void sortColors(vector<int> &nums) {
  int red_cnt = 0;
  int white_cnt = 0;
  int blue_cnt = 0;
  for (auto i : nums) {
    switch (i) {
    case 0:
      ++red_cnt;
      break;
    case 1:
      ++white_cnt;
      break;
    case 2:
      ++blue_cnt;
      break;
    }
  }

  auto next = red_cnt;
  for (auto i = 0; i < red_cnt; ++i) {
    if (nums[i] == 0) {
      continue;
    }

    while (next < nums.size() && nums[next] != 0)
      ++next;
    std::swap(nums[i], nums[next]);
  }

  next = red_cnt + white_cnt;
  for (auto i = red_cnt; i < red_cnt + white_cnt; ++i) {
    if (nums[i] == 1) {
      continue;
    }

    while (next < nums.size() && nums[next] != 1)
      ++next;
    std::swap(nums[i], nums[next]);
  }
}

int main(int argc, char **argv) {
  std::vector<int> nums;
  std::string argv1(argv[1]);
  for (auto c : argv1) {
    nums.push_back(c - '0');
  }
  sortColors(nums);
  PrintVect(nums);
}