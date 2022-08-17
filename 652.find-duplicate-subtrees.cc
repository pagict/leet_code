#include <cstddef>
#include <string>
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

class Solution {
public:
  std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::vector<TreeNode *> result;

    std::unordered_map<TreeNode *, std::string> searched_path;
    auto path = searchPath(root, searched_path);
    searched_path[root] = path;

    for (auto iter : searched_path) {
      printf("[%d] %s\n", iter.first->val, iter.second.c_str());
    }

    return result;
  }

  std::string
  searchPath(TreeNode *root,
             std::unordered_map<TreeNode *, std::string> &searched) {
    if (!root) {
      return "";
    }
    std::string left_path = " ";
    if (root->left) {
      auto &cached_path = searched[root->left];

      if (!cached_path.empty()) {
        left_path = cached_path;
      } else {
        cached_path = searchPath(root->left, searched);
        left_path = cached_path;
      }
    }
    std::string right_path = " ";
    if (root->right) {
      auto &cached = searched[root->right];
      if (!cached.empty()) {
        right_path = cached;
      } else {
        cached = searchPath(root->right, searched);
        right_path = cached;
      }
    }
    return "(" + left_path + ")" + std::to_string(root->val) + "(" +
           right_path + ")";
  }
};

int main(int argc, char **argv) {
  auto solution = Solution();
  auto *root = new TreeNode(
      3,
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(3, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))),
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(5, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))));

  solution.findDuplicateSubtrees(root);
}