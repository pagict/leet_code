#include <string>
#include <vector>

int minSubArrayLen(int target, std::vector<int> &nums) {
  auto start_idx = 0;
  auto sum = 0;
  auto end = 0;
  for (auto i = 0u; i < nums.size(); ++i) {
    const auto n = nums[i];
    if (n >= target) {
      return 1;
    }

    if (sum + n < target) {
      sum += n;
      continue;
    }

    while (sum - nums[start_idx] + n >= target) {
      sum = sum - nums[start_idx];
      start_idx++;
      end = i;
    }
    sum += n;
  }

  if (sum < target) {
    return 0;
  }
  return end - sum;
}

int main(int argc, char **argv) {
  std::vector<int> nums{1, 2, 1, 2, 1, 0, 1, 4, 5, 1, 0, 1, 1, 0, 0, 1};
  printf("minSubArrayLen=%d\n", minSubArrayLen(7, nums));
}