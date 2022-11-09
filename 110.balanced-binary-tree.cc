#include "leetcode_common_struct.h"
#include <map>

// Runtime: 32 ms, faster than 28.94% of C++ online submissions for Balanced
// Binary Tree.
// Memory Usage: 25.8 MB, less than 5.59% of C++ online submissions for Balanced
// Binary Tree.

std::map<TreeNode *, std::pair<int, int>> cache;

void GetChildHeight(TreeNode *root, int &left, int &right) {
  if (!root) {
    left = 0;
    right = 0;
    return;
  }
  auto it = cache.find(root);
  if (it != cache.end()) {
    left = it->second.first;
    right = it->second.second;
    return;
  }
  int a = 0;
  int b = 0;
  left = 0;
  if (root->left) {
    GetChildHeight(root->left, a, b);
    left = std::max(a, b) + 1;
  }
  right = 0;
  if (root->right) {
    GetChildHeight(root->right, a, b);
    right = std::max(a, b) + 1;
  }
  cache[root] = std::make_pair(left, right);
}

bool isBalanced(TreeNode *root) {
  cache.clear();
  int a = 0;
  int b = 0;
  GetChildHeight(root, a, b);
  for (auto it = cache.begin(); it != cache.end(); ++it) {
    if (std::abs(it->second.first - it->second.second) > 1) {
      return false;
    }
  }
  return true;
}