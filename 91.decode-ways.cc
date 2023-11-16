#include <string>
#include <vector>

class Solution {
public:
  int safe_num(int offset) {
    if (s[offset] == '0') {
      return 0;
    }
    int v1 = 0;
    int v2 = 0;
    if (nums[offset + 1]) {
      v1 = s[offset] == '0' ? 0 : nums[offset + 1];
    }
    if (nums[offset + 2]) {
      bool valid =
          (s[offset] == '1' || (s[offset] == '2' && s[offset + 1] < '7'));
      v2 = valid ? nums[offset + 2] : 0;
    }

    return v1 + v2;
  }

  int numDecodings(std::string ss) {
    s = ss;
    nums = std::vector<int>(ss.length(), 0);
    int i = ss.length() - 1;
    if (s[i] == '0') {
      nums[i] = 0;
    } else {
      nums[i] = 1;
    }

    --i;
    if (i < 0) {
      return nums[0];
    }

    if (s[i] == '0') {
      nums[i] = 0;
    } else if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) {
      nums[i] = nums[i + 1] + 1;
    } else {
      nums[i] = nums[i + 1];
    }
    --i;

    while (i >= 0) {
      nums[i] = safe_num(i);
      --i;
    }

    if (s[i + 1] == '0') {
      nums[0] = 0;
    }

    return nums[0];
  }

  std::string s;

  std::vector<int> nums;
};

int main(int argc, char **argv) {
  Solution s;
  printf("%d\n", s.numDecodings(argv[1]));
  return 0;
}