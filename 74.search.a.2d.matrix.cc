#include <vector>

// Runtime 3 ms Beats 74.60 % of users with C++
// 10.03 MB Beats 12.72 % of users with C++

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int xr = 0;
  int xc = 0;
  int yr = matrix.size() - 1;
  int yc = matrix[yr].size();

  int cols = yc;

  if (target < matrix[xr][xc] || target > matrix[yr][yc - 1]) {
    return false;
  }

  while (xr < yr || (xr == yr && xc <= yc)) {
    int len = 0;
    if (xr == yr) {
      len = yc - xc;
    } else {
      len = (yr - xr - 1) * cols + yc + (cols - xc);
    }
    int m = len / 2;
    int mc = (xc + m % cols) % cols;
    int mr = (xr + m / cols) + (xc + m % cols) / cols;

    int m_num = matrix[mr][mc];
    if (target == m_num) {
      return true;
    }

    if (target > m_num) {
      xc = mc + 1;
      xr = mr;
      if (xc == cols) {
        xc = 0;
        ++xr;
      }
    } else {
      yc = mc - 1;
      yr = mr;
      if (yc < 0) {
        yc = cols - 1;
        --yr;
      }
    }
  }
  return false;
}

int main(int argc, char **argv) {
  int target = atoi(argv[1]);
  std::vector<std::vector<int>> matrix{
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  printf("%d\n", searchMatrix(matrix, target));
}