#include <unordered_set>
#include <vector>

bool isValidSudoku(const std::vector<std::vector<char>> &board) {
  std::unordered_set<char> filled;
  const char kEmpty = '.';
  for (auto i = 0u; i < board.size(); ++i) {
    const auto row = board[i];
    filled.clear();
    for (auto j = 0u; j < row.size(); ++j) {
      auto c = row[j];
      if (c == kEmpty) {
        continue;
      }

      if (filled.count(c)) {
        return false;
      }
      filled.insert(c);
    }
  }

  for (auto i = 0u; i < board.size(); ++i) {
    filled.clear();
    for (auto j = 0u; j < board.size(); ++j) {
      auto c = board[j][i];
      if (c == kEmpty) {
        continue;
      }

      if (filled.count(c)) {
        return false;
      }
      filled.insert(c);
    }
  }

  for (auto grid_r = 0u; grid_r < 3; ++grid_r) {
    for (auto grid_c = 0u; grid_c < 3; ++grid_c) {
      filled.clear();
      for (auto i = 0u; i < 3; ++i) {
        for (auto j = 0u; j < 3; ++j) {
          auto c = board[grid_r * 3 + i][grid_c * 3 + j];
          if (c == kEmpty) {
            continue;
          }

          if (filled.count(c)) {
            return false;
          }
          filled.insert(c);
        }
      }
    }
  }

  return true;
}

int main(int argc, char **argv) {
  std::vector<std::vector<char>> board;

  board = {{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
           {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
           {'.', '.', '.', '5', '6', '.', '.', '.', '.'},
           {'4', '.', '3', '.', '.', '.', '.', '.', '1'},
           {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '5', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
  printf("%s\n", isValidSudoku(board) ? "true" : "false");
}