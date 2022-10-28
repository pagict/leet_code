#include <vector>

// Runtime: 24 ms, faster than 30.45% of C++ online submissions for Minimum Path
// Sum.
// Memory Usage: 10.1 MB, less than 31.17% of C++ online submissions for Minimum
// Path Sum.

int CostToRB(const std::vector<std::vector<int>> &grid,
             std::vector<std::vector<int>> &cache, int i, int j) {
  if (i >= grid.size() || j >= grid[0].size()) {
    return 0;
  }
  auto &cache_val = cache[i][j];
  if (cache_val > 0) {
    return cache_val;
  }
  auto next_val = 0;
  if (i == grid.size() - 1 && j == grid[0].size() - 1) {
    next_val = 0;
  }
  if (i == grid.size() - 1) {
    next_val = CostToRB(grid, cache, i, j + 1);
  } else if (j == grid[0].size() - 1) {
    next_val = CostToRB(grid, cache, i + 1, j);
  } else {
    next_val = std::min(CostToRB(grid, cache, i + 1, j),
                        CostToRB(grid, cache, i, j + 1));
  }
  cache_val = next_val + grid[i][j];
  return cache_val;
}

int minPathSum(std::vector<std::vector<int>> &grid) {
  std::vector<std::vector<int>> cache(grid.size(),
                                      std::vector<int>(grid[0].size(), 0));
  int val = CostToRB(grid, cache, 0, 0);
  return val;
}

int main() {
  std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  printf("ret = %d\n", minPathSum(grid));

  grid = {{1, 2, 3}, {4, 5, 6}};
  printf("ret = %d\n", minPathSum(grid));
}