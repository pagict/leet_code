#ifndef _LEETCODE_COMMON_STRUCT_H_
#define _LEETCODE_COMMON_STRUCT_H_
#include <cstdio>
#include <vector>
using ListNode = struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void PrintList(ListNode *head) {
  if (!head) {
    printf("\n");
    return;
  }

  while (head) {
    if (head->next) {
      printf("[%d]->", head->val);
    } else {
      printf("[%d]\n", head->val);
    }
    head = head->next;
  }
}

inline void PrintVect(const std::vector<int> &nums) {
  printf("[");
  if (nums.empty()) {
    printf("]\n");
    return;
  }
  for (auto i = 0u; i < nums.size() - 1; ++i) {
    printf("%d, ", nums[i]);
  }
  printf("%d]\n", nums.back());
}

#endif // !_LEETCODE_COMMON_STRUCT_H_