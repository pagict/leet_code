#include <cmath>
#include <cstddef>
#include <queue>
#include <string>
#include <sys/_types/_size_t.h>
#include <unordered_map>
#include <vector>

using TreeNode = struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void paint(std::vector<std::vector<std::string>> &board, TreeNode *root,
           unsigned row, unsigned col) {
  auto height = board.size() - 1;
  if (!root || row > height) {
    return;
  }
  board[row][col] = std::to_string(root->val);

  auto pow_result = std::pow(2, height - row - 1);
  if (root->left) {
    paint(board, root->left, row + 1, col - pow_result);
  }
  if (root->right) {
    paint(board, root->right, row + 1, col + pow_result);
  }
}

std::vector<std::vector<std::string>> printTree(TreeNode *root) {
  std::vector<std::vector<std::string>> ret;
  if (!root) {
    return {};
  }

  std::vector<TreeNode *> level_q;
  level_q.push_back(root);
  auto level_cnt = 0;
  auto height = 0;
  auto max_at_level = std::pow(2, height) - 1;
  while (!level_q.empty()) {
    auto *p = level_q.front();
    level_q.erase(level_q.begin());
    if (level_cnt > max_at_level && p) {
      ++height;
      max_at_level = std::pow(2, height) - 1;
      level_cnt = 0;
    }
    ++level_cnt;

    if (p) {
      level_q.push_back(p->left);
      level_q.push_back(p->right);
    }
  }

  if (level_cnt < 0) {
    --height;
  }

  auto rows = height + 1;
  auto cols = std::pow<int>(2, rows) - 1;
  printf("=height %d, row %d, col %f\n", height, rows, cols);
  ret = std::vector<std::vector<std::string>>(
      rows, std::vector<std::string>(cols, ""));

  paint(ret, root, 0, (cols - 1) / 2);

  return ret;
}

void print_btree(const std::vector<std::vector<std::string>> &res) {
  printf("===========\n");
  for (auto i = 0u; i < res.size(); ++i) {
    for (auto j = 0u; j < res[i].size(); ++j) {
      printf("%s ", res[i][j].c_str());
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  auto *root = new TreeNode(
      3,
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(9, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))),
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(5, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))));
  // print_btree(printTree(root));

  // root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)),
  //                     new TreeNode(3));
  // print_btree(printTree(root));

  // root = new TreeNode(1, new TreeNode(2), nullptr);
  // print_btree(printTree(root));

  // root = new TreeNode(
  //     1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr),
  //     new TreeNode(5));
  // print_btree(printTree(root));

  // root = new TreeNode(1);
  // print_btree(printTree(root));

  root = new TreeNode(
      3, nullptr,
      new TreeNode(30,
                   new TreeNode(10, nullptr,
                                new TreeNode(15, nullptr, new TreeNode(45))),
                   nullptr));
  print_btree(printTree(root));
}