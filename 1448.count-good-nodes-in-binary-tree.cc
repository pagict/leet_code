#include <cstddef>
#include <cstdio>
#include <cstdlib>

#include <vector>
using TreeNode = struct TreeNode {
  short val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int goodNodes(TreeNode *root) {
  if (!root) {
    return 0;
  }
  int cnt = 0;
  std::vector<std::pair<TreeNode *, int>> parents;
  auto *p = root;
  auto max = p->val;

  while (p || !parents.empty()) {
    while (p) {
      //   printf("[%d] ", p->val);
      if (p->val >= max) {
        ++cnt;
        max = p->val;
      }
      parents.emplace_back(p, max);
      p = p->left;
    }

    auto pv = parents.back();
    p = pv.first;
    max = pv.second;
    parents.pop_back();

    p = p->right;
  }
  return cnt;
}

int main(int argc, char **argv) {
  auto *root = new TreeNode(3, new TreeNode(1, new TreeNode(3), nullptr),
                            new TreeNode(4, new TreeNode(1), new TreeNode(5)));
  printf("goodNodes(root)=%d\n", goodNodes(root));

  root = new TreeNode(2, nullptr,
                      new TreeNode(4, new TreeNode(10),
                                   new TreeNode(8, new TreeNode(4), nullptr)));
  printf("goodNodes(root)=%d\n", goodNodes(root));
}