#include <vector>

// Runtime: 33 ms, faster than 60.62% of C++ online submissions for Special
// Positions in a Binary Matrix.
// Memory Usage: 12.8 MB, less than 77.66% of C++ online submissions for Special
// Positions in a Binary Matrix.

int numSpecial(std::vector<std::vector<int>> &mat) {
  auto cnt = 0;
  for (auto i = 0u; i < mat.size(); ++i) {
    const auto &row = mat[i];
    auto j = 0u;
    while (j < row.size() && row[j] == 0) {
      ++j;
    }
    if (j == row.size()) {
      // no '1' in this row
      continue;
    }

    auto j1 = j + 1;
    while (j1 < row.size() && row[j1] == 0) {
      ++j1;
    }
    if (j1 < row.size()) {
      continue;
    }

    auto k = 0u;
    for (k = 0u; k < mat.size(); ++k) {
      if (k != i && mat[k][j] == 1) {
        break;
      }
    }
    if (k == mat.size()) {
      ++cnt;
    }
  }
  return cnt;
}

int main(int argc, char **argv) {
  std::vector<std::vector<int>> mat{{1, 0, 0}, {0, 0, 1}, {1, 0, 0}};
  printf("numSpecial(...)=%d\n", numSpecial(mat));

  mat = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  printf("numSpecial(...)=%d\n", numSpecial(mat));
}