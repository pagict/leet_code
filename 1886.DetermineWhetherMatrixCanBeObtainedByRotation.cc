#include "leetcode_common_struct.h"
#include <utility>
#include <vector>
using std::vector;

/// 4ms
// Beats 46.05%of users with C++
/// 11.67MB
// Beats 24.01 % of users with C++

bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
  int n = mat.size();
  if (n == 1) {
    return mat[0][0] == target[0][0];
  }
  auto &&get_target_ij = [n](int len, int i, int j) -> std::pair<int, int> {
    int border = (n - len) / 2;
    int t = border, b = n - border;
    int l = border, r = n - border;

    if (i == t && j < r - 1) {
      return {j, r - 1};
    } else if (j == r - 1 && i < b - 1) {
      return {b - 1, n - 1 - i};
    } else if (i == b - 1 && j > l) {
      return {j, l};
    } else {
      /// i== l && j > t
      return {t, b - 1 - i + l};
    }
  };

  auto &&get_next_ij = [n](int len, int i, int j) -> std::pair<int, int> {
    int border = (n - len) / 2;
    int t = border;
    int l = border;
    int r = n - border;
    int b = n - border;

    std::pair<int, int> ij;
    if (i == t && j < r - 1) {
      return {t, j + 1};
    } else if (j == (r - 1) && i < (b - 1)) {
      return {i + 1, r - 1};
    } else if (i == b - 1 && j > l) {
      return {b - 1, j - 1};
    } else {
      //  (j == l && i > t)
      return {i - 1, l};
    }
  };

  auto &&rotate_incr = [=](int incr) -> bool {
    int i = 0;
    int j = 0;
    int length = n;

    while (length > 0) {
      int cnt = 0;
      while (cnt < (2 * length + 2 * (length - 2))) {
        std::pair<int, int> target_ij = {i, j};
        for (int k = 0; k < incr; ++k) {
          target_ij = get_target_ij(length, target_ij.first, target_ij.second);
        }
        if (mat[i][j] != target[target_ij.first][target_ij.second]) {
          return false;
        }
        target_ij = get_next_ij(length, i, j);
        i = target_ij.first;
        j = target_ij.second;
        ++cnt;
      }

      length -= 2;
      i = (n - length) / 2;
      j = i;
    }
    return true;
  };

  for (int i = 1; i <= 4; ++i) {
    if (rotate_incr(i)) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<std::vector<int>> mat{
      {0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 0}};
  std::vector<std::vector<int>> target = {
      {0, 1, 0, 0}, {1, 0, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  printf("%d\n", findRotation(mat, target));
}
