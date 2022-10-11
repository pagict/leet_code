#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> get_nums(int cnt, const std::vector<int> &nums,
                                       std::vector<int> used_idx) {
  std::vector<std::vector<int>> ret;
  if (cnt == 0) {
    ret.push_back(std::vector<int>());
    return ret;
  }
  for (int i = 0; i < nums.size(); ++i) {
    if (std::find(used_idx.begin(), used_idx.end(), i) != used_idx.end()) {
      continue;
    }
    used_idx.push_back(i);
    auto sub_ret = get_nums(cnt - 1, nums, used_idx);
    for (auto &v : sub_ret) {
      v.push_back(nums[i]);
      ret.push_back(v);
    }
  }
  return ret;
}

// Runtime: 20 ms, faster than 5.79% of C++ online submissions for Subsets.
// Memory Usage: 9.3 MB, less than 45.67% of C++ online submissions for Subsets.

std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
  std::vector<std::vector<int>> ret;
  for (int i = 0; i <= nums.size(); ++i) {
    auto sub_ret = get_nums(i, nums, std::vector<int>());
    ret.insert(ret.end(), sub_ret.begin(), sub_ret.end());
  }
  return ret;
}

int main(int argc, char **argv) {
  std::vector<int> nums;
  for (auto i = 1u; i < argc; ++i) {
    nums.push_back(atoi(argv[i]));
  }
  auto ret = subsets(nums);

  std::cout << "[";
  for (auto &v : ret) {
    std::cout << "[";
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << "],";
  }
  std::cout << "]";
}