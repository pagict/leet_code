#include "leetcode_common_struct.h"
#include <vector>

using std::vector;

vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
  vector<int> ret;
  ret.reserve(n);
  int sum = 0;
  for (auto r : rolls) {
    sum += (mean - r);
  }
  sum += mean * n;
  if (sum > 6 * n || sum < n) {
    return ret;
  }

  while (sum != 0) {
    int min = (sum - (n - ret.size()) + 1);
    min = min > 6 ? 6 : min;
    ret.push_back(min);
    sum -= min;
  }

  return ret;
}

int main(int argc, char **argv) {
  int mean = atoi(argv[1]);
  int n = atoi(argv[2]);
  vector<int> rolls;
  for (int i = 3; i < argc; ++i) {
    rolls.push_back(atoi(argv[i]));
  }
  vector<int> ret = missingRolls(rolls, mean, n);
  PrintVect(ret);
}