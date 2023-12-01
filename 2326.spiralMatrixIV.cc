#include "leetcode_common_struct.h"
#include <vector>

using std::vector;

/// 192ms
// Beats 55.42 % of users with C++
/// 128.14MB
// Beats 91.33 % of users with C++

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
  auto ret = std::vector<std::vector<int>>(m, std::vector<int>(n, -1));

  int kSize = m * n;
  int t = 0, l = 0;
  int b = m, r = n;
  int cnt = 0;

  int x = t;
  int y = l;
  ListNode *p = head;
  while (cnt < kSize && p) {
    int layer_cnt = 0;
    int layer_total = 2 * (r - l) + 2 * (b - t - 2);
    if (r - l == 1) {
      layer_total = b - t;
    } else if (b - t == 1) {
      layer_total = r - l;
    }
    while (layer_cnt < layer_total && p) {
      ret[x][y] = p->val;

      p = p->next;
      ++cnt;
      ++layer_cnt;

      if (x == t && y < r - 1) {
        ++y;
      } else if (y == r - 1 && x < b - 1) {
        ++x;
      } else if (x == b - 1 && y > l) {
        --y;
      } else {
        --x;
      }
    }

    ++t;
    ++l;
    --b;
    --r;
    x = t;
    y = l;
  }
  return ret;
}

/// Input: 3 5 "[3,0,2,6,8,1,7,9,4,2,5,5,0]"
int main(int argc, char **argv) {
  int m = std::atoi(argv[1]);
  int n = std::atoi(argv[2]);
  ListNode *root = nullptr;
  ListNode **ptail = &root;
  char *p = argv[3];
  char *ep = p + strlen(argv[3]);
  while (true) {
    while (*p == '[' || *p == ',')
      ++p;
    if (*p == ']')
      break;

    auto num = std::atoi(p);
    *ptail = new ListNode(num, nullptr);
    ptail = &(*ptail)->next;
    while (*p != ']' && *p != ',')
      ++p;
  }
  auto ret = spiralMatrix(m, n, root);

  printf("[\n");
  for (const auto &v : ret) {
    PrintVect(v);
  }
  printf("]\n");
}