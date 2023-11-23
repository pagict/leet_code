#include <cstdlib>
#include <utility>
#include <vector>

#include "leetcode_common_struct.h"

using std::vector;

/// 4ms
// Beats 41.58 % of users with C++
/// 7.44MB
// Beats 40.97 % of users with C++

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int length = n;

  int i = 0;
  int j = 0;

  auto &&get_next_ij = [n](int len, int i, int j) -> std::pair<int, int> {
    int ni = 0;
    int nj = 0;
    int border = (n - len) / 2;
    int t = border;
    int l = border;
    int r = n - border;
    int b = n - border;

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

  std::vector<int> saves;
  while (length > 1) {

    std::pair<int, int> ij;
    while (saves.size() < (2 * length + 2 * (length - 2))) {
      ij = get_next_ij(length, i, j);
      saves.push_back(matrix[i][j]);
      i = ij.first;
      j = ij.second;
    }

    i = (n - length) / 2;
    j = i;

    int idx = saves.size() - length + 1;
    int cnt = 0;

    while (cnt < saves.size()) {
      matrix[i][j] = saves[idx % saves.size()];
      idx++;
      ij = get_next_ij(length, i, j);
      i = ij.first;
      j = ij.second;

      ++cnt;
    }
    saves.clear();
    length -= 2;

    i = (n - length) / 2;
    j = i;
  }
}

/// ./a.out "[[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]"
int main(int argc, char **argv) {
  vector<vector<int>> nums;
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
  printf("]\nOutput:[");
  rotate(nums);
  for (const auto &v : nums) {
    PrintVect(v);
  }
  printf("]\n");
}