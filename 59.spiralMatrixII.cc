#include "leetcode_common_struct.h"
#include <utility>
#include <vector>
using std::vector;

/// 0ms
// Beats 100.00 % of users with C++
/// 7.05MB
// Beats 21.14 % of users with C++

vector<vector<int>> generateMatrix(int n) {
  auto ret = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
  auto &&get_next_ij = [n](int len, int i, int j) {
    int border = (n - len) / 2;
    int t = border, l = border;
    int r = n - border, b = n - border;

    std::pair<int, int> ij;
    if (i == t && j < r - 1) {
      ij = {t, j + 1};
    } else if (j == (r - 1) && i < (b - 1)) {
      ij = {i + 1, r - 1};
    } else if (i == b - 1 && j > l) {
      ij = {b - 1, j - 1};
    } else {
      //  (j == l && i > t)
      ij = {i - 1, l};
    }

    return ij;
  };

  int i = 0, j = 0;
  int len = n;

  int num = 1;
  std::pair<int, int> next;
  while (len > 0) {
    int layer_len = 0;
    if (len > 1) {
      layer_len = 2 * len + 2 * (len - 2);
    } else {
      layer_len = 1;
    }
    int cnt = 0;
    while (cnt < layer_len) {
      ret[i][j] = num++;
      ++cnt;

      next = get_next_ij(len, i, j);
      i = next.first;
      j = next.second;
    }

    len -= 2;
    i = (n - len) / 2;
    j = i;
  }
  return ret;
}

int main(int argc, char **argv) {
  int n = std::atoi(argv[1]);
  auto ret = generateMatrix(n);
  printf("[\n");
  for (const auto &v : ret) {
    PrintVect(v);
  }
  printf("]\n");
}