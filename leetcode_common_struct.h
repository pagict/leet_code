#ifndef _LEETCODE_COMMON_STRUCT_H_
#define _LEETCODE_COMMON_STRUCT_H_
#include <cstdio>
using ListNode = struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode *head) {
  if (!head) {
    printf("\n");
    return;
  }

  while (head) {
    if (head->next) {
      printf("%d->", head->val);
    } else {
      printf("%d\n", head->val);
    }
    head = head->next;
  }
}

#endif // !_LEETCODE_COMMON_STRUCT_H_