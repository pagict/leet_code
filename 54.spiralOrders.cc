#include "leetcode_common_struct.h"
#include <vector>

using std::vector;

/// 0ms
// Beats 100.00 % of users with C++
/// 7.22MB
// Beats 59.62 % of users with C++
vector<int> spiralOrder(vector<vector<int>> &matrix) {
  std::vector<int> ret(matrix.size() * matrix[0].size(), 0);
  int t = 0;
  int b = matrix.size();
  int l = 0;
  int r = matrix[0].size();
  int x = 0;
  int y = 0;
  int idx = 0;

  while (t < b && l < r) {
    int count = 0;
    int layer_count = 2 * (r - l) + 2 * (b - t - 2);
    if (t == b - 1) {
      layer_count = (r - l);
    } else if (r - l == 1) {
      layer_count = b - t;
    }
    while (count < layer_count) {
      ret[idx++] = matrix[x][y];
      ++count;

      if (x == t && y < r - 1) {
        ++y;
      } else if (y == r - 1 && x < b - 1) {
        ++x;
      } else if (x == b - 1 && y > l) {
        --y;
      } else {
        --x;
      }
    }

    ++t;
    --b;
    ++l;
    --r;
    x = t;
    y = l;
  }
  return ret;
}

/// input: "[[6,9,7]]"
int main(int argc, char **argv) {
  std::vector<std::vector<int>> nums;
  char *p = argv[1];
  ++p;

  while (p) {
    if (*p == ']' && *(p - 1) == ']')
      break;

    if (*p == '[') {
      nums.push_back({});
      ++p;
    } else if (*p == ']') {
      ++p;
      while (*p != ']' && *p != '[')
        ++p;
    } else if (*p == ',') {
      ++p;
      while (*p == ',' || *p == '[')
        ++p;
    } else {
      nums.back().push_back(atoi(p));
      ++p;
      while (*p != ',' && *p != ']')
        ++p;
    }
  }

  printf("Input:[");
  for (const auto &v : nums) {
    PrintVect(v);
  }
  printf("]\nOutput:\n");
  PrintVect(spiralOrder(nums));
}