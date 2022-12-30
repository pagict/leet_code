#include <vector>

// Runtime 464ms, beats 35.13%
// Memory 17.9MB, beats 13.62%

std::vector<int> cache;
int jump(int current, const std::vector<int> &nums) {
  if (current >= nums.size() - 1) {
    return 0;
  }
  if (cache[current] > -1) {
    return cache[current];
  }
  if (nums[current] + current >= nums.size() - 1) {
    for (auto i = current; i < cache.size() - 1; ++i) {
      cache[i] = 1;
    }
    cache.back() = 0;
    return 1;
  }
  auto n = 9999;
  for (auto i = current + 1; i <= current + nums[current]; ++i) {
    auto m = jump(i, nums) + 1;
    if (m < n) {
      n = m;
    }
  }
  cache[current] = n;
  return n;
}

int jump(const std::vector<int> &nums) {
  cache = std::vector<int>(nums.size(), -1);
  return jump(0, nums);
}

int main(int argc, char **argv) {
  std::vector<int> nums;
  for (auto i = 1; i < argc; ++i) {
    nums.push_back(std::atoi(argv[i]));
  }
  printf("%d\n", jump(nums));
}