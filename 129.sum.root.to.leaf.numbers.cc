#include "leetcode_common_struct.h"
#include <cstdio>
#include <vector>

// Runtime 5 ms Beats 17.76 % of users with C++
// Memory 9.65 MB Beats 26.59 % of users with C++

int sumNumbers(TreeNode *root) {
  TreeNode *p = root;
  std::vector<TreeNode *> stack{p};
  std::vector<TreeNode *> path{p};
  int current = 0;
  int total = 0;
  while (p && !stack.empty()) {
    current = current * 10 + p->val;
    while (p->left) {
      stack.push_back(p);
      path.push_back(p);
      p = p->left;
      current = current * 10 + p->val;
    }

    if (p->right) {
      path.push_back(p);
      p = p->right;
    } else {
      total += current;
      current = (current - p->val) / 10;

      while (!stack.empty() && !p->right) {
        p = stack.back();
        stack.pop_back();
      }

      TreeNode *q = nullptr;
      while (q != p) {
        q = path.back();
        path.pop_back();
        if (q == p)
          break;
        current = (current - q->val) / 10;
      }
      if (stack.empty()) {
        break;
      }
      path.push_back(p);
      p = p->right;
    }
  }
  return total;
}

int main() {
  TreeNode *root0 =
      new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr),
                   new TreeNode(3, nullptr,
                                new TreeNode(5, nullptr,
                                             new TreeNode(6, new TreeNode(7),
                                                          new TreeNode(8)))));
  TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *root2 = new TreeNode(
      4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
  printf("%d\n", sumNumbers(root0));
}