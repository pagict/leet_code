#include <algorithm>
#include <cmath>
#include <cstddef>
#include <map>
#include <string>
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

std::map<unsigned, std::vector<unsigned>> level_idx;

void dfs(TreeNode *node, unsigned height, unsigned idx) {
  if (!node) {
    return;
  }

  level_idx[height].push_back(idx);
  auto two_times = idx << 1;
  if (node->left) {
    dfs(node->left, height + 1, two_times);
  }
  if (node->right) {
    dfs(node->right, height + 1, two_times + 1);
  }
}

// Runtime: 21 ms, faster than 21.37% of C++ online submissions for Maximum
// Width of Binary Tree. Memory Usage: 20 MB, less than 5.14% of C++ online
// submissions for Maximum Width of Binary Tree.

int widthOfBinaryTree(TreeNode *root) {
  // printf("=====\n");
  if (!root) {
    return 0;
  }
  level_idx.clear();
  dfs(root, 0, 0);
  auto max = 0;
  for (auto &level_nodeidx : level_idx) {
    auto &idx = level_nodeidx.second;
    if (idx.empty()) {
      continue;
    }
    std::sort(idx.begin(), idx.end());
    auto width = idx.back() - idx.front() + 1;
    if (max < width) {
      max = width;
    }
  }
  return max;
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
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1, nullptr, new TreeNode(3, new TreeNode(4), nullptr));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)),
                      new TreeNode(3));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1, new TreeNode(2), nullptr);
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(
      1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr),
      new TreeNode(5));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1);
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(
      3, nullptr,
      new TreeNode(30,
                   new TreeNode(10, nullptr,
                                new TreeNode(15, nullptr, new TreeNode(45))),
                   nullptr));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(
      1, new TreeNode(3, new TreeNode(5, new TreeNode(6), nullptr), nullptr),
      new TreeNode(2, nullptr, new TreeNode(9, new TreeNode(7), nullptr)));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1, new TreeNode(3, new TreeNode(5), nullptr),
                      new TreeNode(2));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  auto *left_child1 = new TreeNode(2, new TreeNode(2), nullptr);
  auto *left_child2 = new TreeNode(2, new TreeNode(2), nullptr);
  auto *right_child1 = new TreeNode(2, nullptr, new TreeNode(2));
  auto *right_child2 = new TreeNode(2, nullptr, new TreeNode(2));
  auto *two_left_grandsons = new TreeNode(2, left_child1, left_child2);
  auto *two_right_grandsons = new TreeNode(2, right_child1, right_child2);
  auto *tmp = new TreeNode(1, two_left_grandsons, two_right_grandsons);
  root = new TreeNode(
      1, new TreeNode(1, new TreeNode(1), new TreeNode(1, nullptr, tmp)),
      new TreeNode(1, new TreeNode(1), new TreeNode(1)));
  printf("max_width=%d\n", widthOfBinaryTree(root));
}