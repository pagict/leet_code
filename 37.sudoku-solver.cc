#include <array>
#include <unordered_set>
#include <vector>

class Solution {
public:
  const char kEmpty = '.';
  const std::array<char, 9> kCandiesAll = {'1', '2', '3', '4', '5',
                                           '6', '7', '8', '9'};
  bool FillCell(size_t row, size_t col) {
    if (board_->at(row)[col] != kEmpty) {
      return true;
    }
    const auto candies = GetCandicatesForCell(row, col);
    if (candies.size() == 0) {
      return false;
    }
    if (candies.size() == 1) {
      board_->at(row)[col] = candies.front();
      auto next_row = row;
      auto next_col = col + 1;
      FindNextEmptyCell(&next_row, &next_col);
      if (next_row == row_num && next_col == col_num) {
        return true;
      }

      if (FillCell(next_row, next_col)) {
        return true;
      }

      board_->at(row)[col] = kEmpty;
      return false;
    }

    for (auto c : candies) {
      board_->at(row)[col] = c;
      auto next_row = row;
      auto next_col = col + 1;
      FindNextEmptyCell(&next_row, &next_col);
      if (next_row >= row_num || next_col >= col_num) {
        return true;
      }

      auto tmp = FillCell(next_row, next_col);
      if (tmp) {
        return true;
      }
    }
    board_->at(row)[col] = kEmpty;
    return false;
  }

  void FindNextEmptyCell(size_t *row, size_t *col) {
    if (*row >= row_num) {
      *row = row_num;
      *col = col_num;
      return;
    }

    if (*col >= col_num) {
      *col = 0;
      *row = *row + 1;
    }
    auto i_row = *row;

    auto last_j = *col;
    for (auto i = i_row; i < row_num; ++i) {
      for (auto j = last_j; j < col_num; ++j) {
        if (board_->at(i)[j] == kEmpty) {
          *row = i;
          *col = j;
          return;
        }
      }
      last_j = 0;
    }

    *row = row_num;
    *col = col_num;
  }

  std::vector<char> GetCandicatesForCell(size_t row_idx, size_t col_idx) {
    std::unordered_set<char> candies(kCandiesAll.begin(), kCandiesAll.end());
    const auto &row = board_->at(row_idx);
    for (auto c : row) {
      if (c != kEmpty) {
        candies.erase(c);
      }
    }
    for (auto i = 0u; i < board_->size(); ++i) {
      auto c = board_->at(i)[col_idx];
      if (c != kEmpty) {
        candies.erase(board_->at(i)[col_idx]);
      }
    }

    auto grid_row_start = row_idx / 3 * 3;
    auto grid_col_start = col_idx / 3 * 3;
    for (auto i = grid_row_start; i < grid_row_start + 3; ++i) {
      for (auto j = grid_col_start; j < grid_col_start + 3; ++j) {
        auto c = board_->at(i)[j];
        if (c != kEmpty) {
          candies.erase(c);
        }
      }
    }

    return std::vector<char>{candies.begin(), candies.end()};
  }

  void solveSudoku(std::vector<std::vector<char>> &board) {
    board_ = &board;
    row_num = board.size();
    col_num = board[0].size();

    size_t i = 0;
    size_t j = 0;
    FindNextEmptyCell(&i, &j);
    FillCell(i, j);
  }

  std::vector<std::vector<char>> *board_;
  size_t row_num = 0;
  size_t col_num = 0;
};

void print_boad(const std::vector<std::vector<char>> &b) {
  for (auto i = 0u; i < b.size(); ++i) {
    const auto &row = b[i];
    for (auto j = 0u; j < row.size() - 1; ++j) {
      printf("%c ", row[j]);
    }
    printf("%c\n", row[row.size() - 1]);
  }
}

int main(int argc, char **argv) {
  std::vector<std::vector<char>> board{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution s;
  s.solveSudoku(board);
  print_boad(board);

  board = {{'.', '.', '.', '1', '.', '.', '2', '.', '7'},
           {'9', '.', '.', '.', '4', '.', '.', '.', '.'},
           {'.', '.', '.', '.', '.', '.', '.', '3', '.'},
           {'5', '.', '.', '.', '.', '6', '3', '.', '.'},
           {'.', '.', '.', '.', '3', '.', '.', '.', '.'},
           {'.', '2', '.', '7', '.', '.', '.', '1', '6'},
           {'.', '.', '.', '.', '.', '.', '1', '.', '.'},
           {'3', '6', '4', '.', '.', '7', '.', '.', '9'},
           {'.', '.', '.', '.', '.', '9', '5', '.', '.'}};
  s.solveSudoku(board);
  print_boad(board);
}