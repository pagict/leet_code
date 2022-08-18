#include <cstddef>
#include <cstdio>
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

    std::unordered_map<std::string, std::vector<TreeNode *>> searched_path;
    searchPath(root, searched_path);

    for (const auto &iter : searched_path) {
      if (iter.second.size() > 1) {
        result.push_back(iter.second.front());
      }
    }

    return result;
  }

  std::string searchPath(
      TreeNode *root,
      std::unordered_map<std::string, std::vector<TreeNode *>> &searched) {
    std::string path;
    if (!root) {
      return "";
    }
    std::string left_path = " ";
    if (root->left) {
      left_path = searchPath(root->left, searched);
    }
    std::string right_path = " ";
    if (root->right) {
      right_path = searchPath(root->right, searched);
    }

    path = "(" + left_path + ")" + std::to_string(root->val) + "(" +
           right_path + ")";
    searched[path].push_back(root);
    return path;
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