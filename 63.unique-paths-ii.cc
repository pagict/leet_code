#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <malloc/_malloc.h>
#include <vector>

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    board_.clear();
    for (auto i = 0u; i < obstacleGrid.size(); ++i) {
      board_.emplace_back(obstacleGrid[i].size(), -1);
      for (auto j = 0u; j < obstacleGrid[i].size(); ++j) {
        if (obstacleGrid[i][j] == 1) {
          board_[i][j] = 0;
        }
      }
    }
    if (board_[0][0] == -1) {
      board_[0][0] = 1;
    }
    return PathsToPoint(obstacleGrid[0].size() - 1, obstacleGrid.size() - 1);
  }

  int PathsToPoint(int h, int w) {
    auto cached = board_[w][h];
    if (cached != -1) {
      return cached;
    }

    int paths = 0;
    if (h == 0) {
      paths = PathsToPoint(h, w - 1);
    } else if (w == 0) {
      paths = PathsToPoint(h - 1, w);
    } else {
      paths = PathsToPoint(h, w - 1) + PathsToPoint(h - 1, w);
    }
    board_[w][h] = paths;
    return paths;
  }

private:
  std::vector<std::vector<int>> board_;
};

int main(int argc, char **argv) {

  Solution s;

  std::vector<std::vector<int>> obstacleGrid;

  obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  printf("uniquePathsWithObstacles(...)=%d\n",
         s.uniquePathsWithObstacles(obstacleGrid));

  obstacleGrid = {{1}};
  printf("uniquePathsWithObstacles(...)=%d\n",
         s.uniquePathsWithObstacles(obstacleGrid));

  obstacleGrid = {{0, 0}};
  printf("uniquePathsWithObstacles(...)=%d\n",
         s.uniquePathsWithObstacles(obstacleGrid));
  return 0;
}