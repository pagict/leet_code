#include <stdio.h>
#include <stdlib.h>

#include <vector>

typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = nullptr;
    right = nullptr;
  }
} TreeNode;

void flatten(TreeNode *root) {
  if (!root)
    return;

  std::vector<TreeNode *> right_child_stack;

  TreeNode *node = root;
  while (node) {
    while (node && node->left) {
      if (node->right) {
        right_child_stack.push_back(node->right);
      }

      node->right = node->left;
      node->left = nullptr;
      node = node->right;
    }

    // node->right == NULL
    if (node->right) {
      node = node->right;
    } else {
      if (right_child_stack.size() > 0) {
        TreeNode *tmpnode = node->right = right_child_stack.back();
        right_child_stack.pop_back();
        node->right = tmpnode;
        node = tmpnode;
      } else {
        node = nullptr;
      }
    }
  }
}

void print_right_tree(TreeNode *root) {
  if (!root)
    return;

  TreeNode *node = root;
  while (node) {
    printf("%d ", node->val);
    if (node->right) {
      printf("-> ");
    }
    node = node->right;
  }
  printf("\n");
}

int main(int argc, char **argv) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->right = new TreeNode(6);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(8);
  flatten(root);
  print_right_tree(root);
}