#include "leetcode_common_struct.h"
ListNode *mergeNodes(ListNode *head) {
  ListNode *last_zero = head;
  while (last_zero->next) {
    ListNode *p = last_zero->next;
    int sum = 0;
    while (p && p->val != 0) {
      sum += p->val;
      p = p->next;
    }

    last_zero->val = sum;

    if (!p->next) {
      last_zero->next = nullptr;
    } else {
      last_zero->next = p;
    }

    last_zero = p;
  }
  return head;
}

int main(int argc, char **argv) {
  ListNode *head = nullptr;
  ListNode **p = &head;
  for (int i = 1; i < argc; ++i) {
    int val = atoi(argv[i]);
    *p = new ListNode(val);
    p = &(*p)->next;
  }

  ListNode *ret = mergeNodes(head);
  PrintList(ret);
}