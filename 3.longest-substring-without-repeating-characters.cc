#include <string>
#include <vector>

// Runtime 12ms, beats 88.37%
// Memory 7.5MB, beats 87.24%

int lengthOfLongestSubstring(std::string s) {
  if (s.empty()) {
    return 0;
  }
  std::vector<int> dp(s.size(), 0);
  int max = 1;
  dp[0] = 1;

  for (auto i = 1; i < s.size(); ++i) {
    auto j = i - 1;
    auto prev = dp[j];
    for (; j >= 0 && j > i - 1 - prev; j--) {
      if (s[j] == s[i]) {
        dp[i] = i - j;
        break;
      }
    }
    if (j == i - 1 - prev) {
      dp[i] = prev + 1;
    }
    if (dp[i] > max) {
      max = dp[i];
    }
  }
  return max;
}

int main(int argc, char **argv) {
  std::string s;
  if (argc > 1) {
    s = argv[1];
  }
  printf("%d\n", lengthOfLongestSubstring(s));
}