#include <algorithm>
#include <functional>
#include <vector>
int maxProduct(std::vector<int> &nums) {
  std::nth_element(nums.begin(), nums.begin() + 1, nums.end(),
                   std::greater<>());
  return (nums[0] - 1) * (nums[1] - 1);
  return 0;
}

int main(int argc, char **argv) {
  std::vector<int> nums;
  for (auto i = 1; i < argc; ++i) {
    nums.push_back(std::atoi(argv[i]));
  }
  printf("result=%d\n", maxProduct(nums));
}