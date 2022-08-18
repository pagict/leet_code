#include <cstddef>
#include <cstring>
#include <string>

using TreeNode = struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

template <class T> void AppendValue(std::string &buf, T val) {
  buf.append(sizeof(T), 0x00);
  auto p = const_cast<char *>(buf.c_str());
  p += buf.length() - sizeof(T);
  memcpy(p, &val, sizeof(T));
}

void SerializeTree(TreeNode *root, std::string &buf) {
  if (!root) {
    AppendValue(buf, (short)-1);
    return;
  } else {
    AppendValue(buf, (short)root->val);
  }
  SerializeTree(root->left, buf);
  SerializeTree(root->right, buf);
}

// Encodes a tree to a single string.
std::string serialize(TreeNode *root) {
  std::string bytes;
  SerializeTree(root, bytes);
  return bytes;
}

template <typename ValType>
size_t DeserializeNode(const std::string &buf, size_t offset, TreeNode **node) {
  if (offset >= buf.length()) {
    return offset;
  }
  auto *p = const_cast<char *>(buf.c_str());
  p += offset;
  ValType t;
  memcpy(&t, p, sizeof(ValType));

  if (t < 0) {
    *node = nullptr;
    return offset + sizeof(ValType);
  }

  *node = new TreeNode(t);
  auto left_offset =
      DeserializeNode<ValType>(buf, offset + sizeof(ValType), &((*node)->left));
  auto right_offset =
      DeserializeNode<ValType>(buf, left_offset, &((*node)->right));
  return right_offset;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(const std::string &data) {
  TreeNode *root;
  DeserializeNode<short>(data, 0, &root);
  return root;
}

int main(int argc, char **argv) {
  auto *root = new TreeNode(
      3,
      new TreeNode(
          4, new TreeNode(10000),
          new TreeNode(3, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))),
      new TreeNode(
          4, new TreeNode(2),
          new TreeNode(5, nullptr, new TreeNode(7, nullptr, new TreeNode(8)))));

  const auto bytes1 = serialize(root);
  auto *de_tree = deserialize(bytes1);
  const auto bytes2 = serialize(de_tree);

  if (bytes1.length() != bytes2.length()) {
    printf("length not match\n");
    return -1;
  }
  for (auto i = 0u; i < bytes1.length(); ++i) {
    if (bytes1[i] != bytes2[i]) {
      printf("val at %u not match %u %u\n", i, (unsigned char)bytes1[i],
             (unsigned char)bytes2[i]);
      return -1;
    }
  }
  printf("ok\n");
  return 0;
}