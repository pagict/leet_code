#include <vector>

using std::vector;

// Runtime: 1143 ms, faster than 30.30% of C++ online submissions for Burst
// Balloons.
// Memory Usage: 10.3 MB, less than 54.07% of C++ online submissions for Burst
// Balloons.

int maxCoins(vector<int> &nums) {
  auto n = nums.size();
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  std::vector<std::vector<int>> c(n + 2, std::vector<int>(n + 2, 0));
  for (auto l = 1; l < n + 1; ++l) {
    for (auto i = 1; i <= n + 1 - l; ++i) {
      auto j = i + l - 1;
      for (auto k = i; k <= j; ++k) {
        c[i][j] = std::max(c[i][j], c[i][k - 1] + c[k + 1][j] +
                                        nums[i - 1] * nums[k] * nums[j + 1]);
      }
    }
  }
  return c[1][n];
}

int main(int argc, char **argv) {
  vector<int> nums;
  for (auto i = 1; i < argc; ++i) {
    nums.push_back(std::atoi(argv[i]));
  }
  printf("%d\n", maxCoins(nums));
}