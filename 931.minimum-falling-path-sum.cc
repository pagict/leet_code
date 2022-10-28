#include <limits>
#include <vector>

// Runtime: 32 ms, faster than 50.48% of C++ online submissions for Minimum
// Falling Path Sum.
// Memory Usage: 10.3 MB, less than 27.80% of C++ online submissions for Minimum
// Falling Path Sum.

int FallingCost(const std::vector<std::vector<int>> &matrix,
                std::vector<std::vector<int>> &cache, int row, int col) {
  if (row == matrix.size() - 1) {
    return matrix[row][col];
  }
  auto &cache_val = cache[row][col];
  if (cache_val != std::numeric_limits<int>::max()) {
    return cache_val;
  }
  int val_0 = FallingCost(matrix, cache, row + 1, col);
  int val_1 = val_0;
  int val_2 = val_0;
  if (col == 0) {
    val_1 = FallingCost(matrix, cache, row + 1, col + 1);
  } else if (col == matrix[0].size() - 1) {
    val_2 = FallingCost(matrix, cache, row + 1, col - 1);
  } else {
    val_1 = FallingCost(matrix, cache, row + 1, col + 1);
    val_2 = FallingCost(matrix, cache, row + 1, col - 1);
  }
  cache_val = std::min(val_0, std::min(val_1, val_2)) + matrix[row][col];
  return cache_val;
}

int minFallingPathSum(std::vector<std::vector<int>> &matrix) {
  int val = std::numeric_limits<int>::max();
  std::vector<std::vector<int>> cache(
      matrix.size(),
      std::vector<int>(matrix[0].size(), std::numeric_limits<int>::max()));
  for (auto i = 0; i < matrix[0].size(); ++i) {
    auto cost = FallingCost(matrix, cache, 0, i);
    if (val > cost) {
      val = cost;
    }
  }
  return val;
}

int main() {
  std::vector<std::vector<int>> matrix;
  matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  printf("ret=%d\n", minFallingPathSum(matrix));

  matrix = {{-19, 57}, {-40, -5}};
  printf("ret=%d\n", minFallingPathSum(matrix));

  matrix = {{17, 82}, {1, -44}};
  printf("ret=%d\n", minFallingPathSum(matrix));
}