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

TreeNode *ContructMaxBTreeInRange(const std::vector<int> &nums, unsigned beg,
                                  unsigned end) {
  if (beg >= end || beg >= nums.size()) {
    return nullptr;
  }
  auto max = nums[beg];
  auto max_idx = beg;
  for (auto i = beg; i < end; ++i) {
    if (nums[i] > max) {
      max = nums[i];
      max_idx = i;
    }
  }

  return new TreeNode(max, ContructMaxBTreeInRange(nums, beg, max_idx),
                      ContructMaxBTreeInRange(nums, max_idx + 1, end));
}

TreeNode *constructMaximumBinaryTree(const std::vector<int> &nums) {
  return ContructMaxBTreeInRange(nums, 0, nums.size());
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
  std::vector<int> nums{3, 2, 1, 6, 0, 5};
  LevelPrintTree(constructMaximumBinaryTree(nums));
}