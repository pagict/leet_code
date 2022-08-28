#include <cmath>
#include <string>
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
  printf("=====\n");
  if (!root) {
    return 0;
  }
  std::vector<TreeNode *> queue{root};
  auto valid_nodes = 1u;
  auto height = 0u;
  auto max_in_level = std::pow(2, height);
  auto level_cnt = 0;

  auto max_width = 0;

  while (!queue.empty()) {
    auto *p = queue.front();
    queue.erase(queue.begin());
    while (level_cnt >= max_in_level) {
      level_cnt -= max_in_level;
      ++height;
      max_in_level = std::pow(2, height);
      if (valid_nodes > 0 && !queue.empty()) {
        auto i = 0u;
        for (; i < queue.size(); ++i) {
          if (queue[i])
            break;
        }
        auto j = queue.size() - 1;
        for (; j >= 0; --j) {
          if (queue[j])
            break;
        }
        auto width = j; // or j
        if (width > max_width) {
          max_width = width;
        }
      }
    }
    printf("num(%s) at height:%d, cnt:%u\n",
           p ? std::to_string(p->val).c_str() : "null", height, level_cnt);
    ++level_cnt;

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
      if (valid_nodes) {
        queue.push_back(nullptr);
        queue.push_back(nullptr);
      }
    }
  }
  return max_width;
}

int main(int argc, char **argv) {
  auto *root = new TreeNode(
      3,
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(9, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))),
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(5, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)),
                      new TreeNode(3));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1, new TreeNode(2), nullptr);
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(
      1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr),
      new TreeNode(5));
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(1);
  printf("max_width=%d\n", widthOfBinaryTree(root));

  root = new TreeNode(
      3, nullptr,
      new TreeNode(30,
                   new TreeNode(10, nullptr,
                                new TreeNode(15, nullptr, new TreeNode(45))),
                   nullptr));
  printf("max_width=%d\n", widthOfBinaryTree(root));
}