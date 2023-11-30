#include "leetcode_common_struct.h"
#include <vector>

using std::vector;

/// 12ms
// Beats 64.63 % of users with C++
/// 11.21MB
// Beats 94.53 % of users with C++

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                    int cStart) {
  auto ret = std::vector<std::vector<int>>(rows * cols, std::vector<int>(2, 0));
  auto kMax = rows * cols;
  int idx = 0;
  int b = rStart + 2;
  int t = rStart;
  int l = cStart;
  int r = cStart + 2;
  int len = 2;
  int layer_len = 4;
  int x = rStart;
  int y = cStart;
  while (idx < kMax) {
    int cnt = 0;

    while (cnt < layer_len && idx < kMax) {
      if (x >= 0 && x < rows && y >= 0 && y < cols) {
        ret[idx][0] = x;
        ret[idx++][1] = y;
      }
      ++cnt;

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

    ++b;
    --t;
    --l;
    ++r;
    x = b - 2;
    y = l;
    len += 2;
    layer_len = 2 * len + (len - 2) * 2;
  }
  return ret;
}

int main(int argc, char **argv) {
  int rows = std::atoi(argv[1]);
  int cols = std::atoi(argv[2]);
  int rStart = std::atoi(argv[3]);
  int cStart = std::atoi(argv[4]);
  auto ret = spiralMatrixIII(rows, cols, rStart, cStart);

  printf("[");
  for (const auto &r : ret) {
    PrintVect(r);
    printf(",");
  }
  printf("]\n");
}