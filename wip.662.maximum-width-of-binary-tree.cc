#include <cmath>
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

int widthOfBinaryTree(TreeNode *root) {
  if (!root) {
    return 0;
  }
  std::vector<TreeNode *> queue{root};
  auto valid_nodes = 1u;
  auto height = 0u;
  auto max_in_level = std::pow(2, height);
  auto level_cnt = 0;
  while (!queue.empty()) {
    auto *p = queue.front();
    queue.erase(queue.begin());
    if (p) {
      queue.push_back(p->left);
      queue.push_back(p->right);
      if (p->left) {
        ++valid_nodes;
      }
      if (p->right) {
        ++valid_nodes;
      }
      --valid_nodes;
    } else {
    }
  }
  return 0;
}