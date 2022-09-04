#include <cstdio>
#include <unordered_map>
#include <utility>
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

// Runtime: 349 ms, faster than 5.13% of C++ online submissions for Longest
// Univalue Path.
// Memory Usage: 103.5 MB, less than 6.53% of C++ online submissions for Longest
// Univalue Path.

std::unordered_map<TreeNode *, std::pair<unsigned, unsigned>>
    sameval_path_cache;

std::pair<unsigned, unsigned> SameValPath(TreeNode *root) {
  if (!root) {
    return std::make_pair(0, 0);
  }
  auto iter = sameval_path_cache.find(root);
  if (iter != sameval_path_cache.end()) {
    return iter->second;
  }

  std::pair<unsigned, unsigned> left_path;
  std::pair<unsigned, unsigned> right_path;
  if (root->left) {
    auto tmp = SameValPath(root->left);
    if (root->left->val == root->val) {
      left_path = tmp;
      ++left_path.first;
      ++left_path.second;
    }
  }
  if (root->right) {
    auto tmp = SameValPath(root->right);
    if (root->right->val == root->val) {
      right_path = tmp;
      ++right_path.first;
      ++right_path.second;
    }
  }

  auto res = std::max(left_path, right_path);
  sameval_path_cache.emplace(
      root, std::make_pair(std::max(left_path.first, left_path.second),
                           std::max(right_path.first, right_path.second)));
  return res;
}

int longestUnivaluePath(TreeNode *root) {
  if (!root) {
    return 0;
  }
  sameval_path_cache.clear();
  auto max_path_length = 0;

  SameValPath(root);

  for (auto &iter : sameval_path_cache) {
    auto len = iter.second.first + iter.second.second;
    if (len > max_path_length) {
      max_path_length = len;
    }
  }
  return max_path_length;
}

int main(int argc, char **argv) {
  TreeNode *root = nullptr;
  root = new TreeNode(5, new TreeNode(4, new TreeNode(1), new TreeNode(1)),
                      new TreeNode(5, nullptr, new TreeNode(5)));
  printf("longestUnivaluePath(...)=%d\n", longestUnivaluePath(root));

  root = new TreeNode(1, new TreeNode(4, new TreeNode(4), new TreeNode(4)),
                      new TreeNode(5, nullptr, new TreeNode(5)));
  printf("longestUnivaluePath(...)=%d\n", longestUnivaluePath(root));

  root = new TreeNode(1, new TreeNode(4, new TreeNode(4), new TreeNode(4)),
                      new TreeNode(5, nullptr, new TreeNode(5)));
  printf("longestUnivaluePath(...)=%d\n", longestUnivaluePath(root));

  root = new TreeNode(
      1, nullptr,
      new TreeNode(1, new TreeNode(1, new TreeNode(1), new TreeNode(1)),
                   new TreeNode(1, new TreeNode(1), nullptr)));
  printf("longestUnivaluePath(...)=%d\n", longestUnivaluePath(root));
}
