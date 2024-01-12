#include <vector>

#include "leetcode_common_struct.h"

/// 3 ms Beats 56.97 % of users with C++
/// 12.24 MB Beats 98.58 % of users with C++

inline TreeNode *pop_next(std::vector<TreeNode *> &nodes, int level_end,
                          int is_stack) {
  if (nodes.empty()) {
    return nullptr;
  }
  if (is_stack) {
    auto iter = nodes.begin() + (level_end - 1);
    auto p = *iter;
    nodes.erase(iter);
    return p;
  } else {
    auto p = nodes.front();
    nodes.erase(nodes.begin());
    return p;
  }
}
inline void push_next(TreeNode *p, std::vector<TreeNode *> &nodes,
                      int level_end, int is_stack) {
  if (is_stack) {
    if (p->right) {
      nodes.insert(nodes.begin() + level_end, p->right);
    }
    if (p->left) {
      nodes.insert(nodes.begin() + level_end, p->left);
    }
  } else {
    if (p->left) {
      nodes.push_back(p->left);
    }
    if (p->right) {
      nodes.push_back(p->right);
    }
  }
}

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
  if (!root) {
    return {};
  }
  std::vector<std::vector<int>> ret{{}};
  std::vector<TreeNode *> level_cache{root};
  int level_cnt = 1;
  int is_stack = 0;
  while (!level_cache.empty()) {
    auto p = pop_next(level_cache, level_cnt, is_stack);
    ret.back().push_back(p->val);
    --level_cnt;

    push_next(p, level_cache, level_cnt, is_stack);
    if (level_cnt == 0) {
      level_cnt = level_cache.size();
      is_stack = (is_stack + 1) % 2;
      if (level_cnt) {
        ret.push_back({});
      }
    }
  }
  return ret;
}

int main() {
  auto root = new TreeNode(3, new TreeNode(9),
                           new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  auto ret = zigzagLevelOrder(root);
  for (const auto v : ret) {
    PrintVect(v);
  }
}