#include <vector>

// 59 ms Beats 91.63 % of users with C++
// 17.38 MB Beats 5.36 % of users with C++

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
  int m = matrix.size();
  int n = matrix[m - 1].size();
  int start = 0;
  int end = n - 1;
  while (start < m && end >= 0) {
    int num = matrix[start][end];
    if (num == target) {
      return true;
    }
    if (num > target) {
      --end;
    } else {
      ++start;
    }
  }
  return false;
}

int main(int argc, char **argv) {
  int target = atoi(argv[1]);
  std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15},
                                       {2, 5, 8, 12, 19},
                                       {3, 6, 9, 16, 22},
                                       {10, 13, 14, 17, 24},
                                       {18, 21, 23, 26, 30}};
  //   std::vector<std::vector<int>> matrix{{1, 1}};
  printf("%d\n", searchMatrix(matrix, target));
}