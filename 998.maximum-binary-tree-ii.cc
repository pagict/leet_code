#include <algorithm>
#include <cstddef>
#include <cstdio>
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

// Runtime: 10 ms, faster than 37.93% of C++ online submissions for Maximum
// Binary Tree II.
// Memory Usage: 13.6 MB, less than 32.51% of C++ online submissions for Maximum
// Binary Tree II.

TreeNode *ContructMaxBTreeInRange(const std::vector<TreeNode *> &nodes,
                                  unsigned beg, unsigned end) {
  if (beg >= end || beg >= nodes.size()) {
    return nullptr;
  }
  auto *p = nodes[beg];
  auto max_idx = beg;
  for (auto i = beg; i < end; ++i) {
    if (nodes[i]->val > p->val) {
      p = nodes[i];
      max_idx = i;
    }
  }

  p->left = ContructMaxBTreeInRange(nodes, beg, max_idx);
  p->right = ContructMaxBTreeInRange(nodes, max_idx + 1, end);
  return p;
}

TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
  std::vector<TreeNode *> nodes;
  auto *p = root;
  std::vector<TreeNode *> stack;
  while (p || !stack.empty()) {
    while (p) {
      stack.push_back(p);
      p = p->left;
    }

    p = stack.back();
    stack.erase(std::prev(stack.end()));
    nodes.push_back(p);
    p = p->right;
  }
  for (auto *p : nodes) {
    p->left = p->right = nullptr;
  }
  nodes.push_back(new TreeNode(val));
  return ContructMaxBTreeInRange(nodes, 0, nodes.size());
}

void LevelPrintTree(TreeNode *root) {
  if (!root) {
    printf("[null]\n");
    return;
  }
  printf("[");
  std::vector<TreeNode *> stack{root};
  while (!stack.empty()) {
    auto *p = stack.front();
    stack.erase(stack.begin());

    if (p == nullptr) {
      printf("null ");
    } else {
      printf("%d ", p->val);
      stack.push_back(p->left);
      stack.push_back(p->right);
    }
  }
  printf("]\n");
}

int main() {
  TreeNode *root = nullptr;
  int val = 0;

  root = new TreeNode(4, new TreeNode(1),
                      new TreeNode(3, new TreeNode(2), nullptr));
  val = 5;
  LevelPrintTree(constructII(root, val));

  root = new TreeNode(5, new TreeNode(2, nullptr, new TreeNode(1)),
                      new TreeNode(3));
  val = 4;
  LevelPrintTree(constructII(root, val));
}