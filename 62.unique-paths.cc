#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <malloc/_malloc.h>
#include <vector>

class Solution {
public:
  int uniquePaths(int m, int n) {

    board_h_ = m;
    board_w_ = n;

    board_.clear();
    for (auto i = 0u; i < n; ++i) {
      board_.emplace_back(m, -1);
    }

    board_[0][0] = 1;
    return PathsToPoint(board_h_ - 1, board_w_ - 1);
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
  int board_w_;
  int board_h_;
};

int main(int argc, char **argv) {
  if (argc != 3) {
    return -1;
  }

  int m = std::atoi(argv[1]);
  int n = std::atoi(argv[2]);
  Solution s;
  printf("uniquePaths(%d, %d)=%d\n", m, n, s.uniquePaths(m, n));
  return 0;
}