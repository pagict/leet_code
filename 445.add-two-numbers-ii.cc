#include "leetcode_common_struct.h"
#include <cstddef>

// Runtime: 62 ms, faster than 62.17% of C++ online submissions for Add Two
// Numbers II. Memory Usage: 71.2 MB, less than 67.27% of C++ online submissions
// for Add Two Numbers II.

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode fake(0, l1);
  auto *p = l1;
  auto *q = &fake;
  while (p) {
    auto *tmp = p->next;
    p->next = q;
    q = p;
    p = tmp;
  }
  l1 = q;
  fake.next->next = nullptr;

  fake.next = l2;
  p = l2;
  q = &fake;
  while (p) {
    auto *tmp = p->next;
    p->next = q;
    q = p;
    p = tmp;
  }
  l2 = q;
  fake.next->next = nullptr;

  p = l1;
  q = l2;
  fake.next = nullptr;
  auto *r = &fake;
  int addon = 0;
  while (p && q) {
    auto num = p->val + q->val + addon;
    p = p->next;
    q = q->next;

    if (num < 10) {
      r->next = new ListNode(num, nullptr);
      addon = 0;
    } else {
      r->next = new ListNode(num % 10, nullptr);
      addon = 1;
    }
    r = r->next;
  }
  r->next = p ? p : q;
  q = r;
  r = r->next;
  while (addon && r) {
    auto n = r->val + addon;
    r->val = n % 10;
    if (n < 10) {
      addon = 0;
      break;
    }

    addon = 1;
    q = r;
    r = r->next;
  }
  if (addon) {
    q->next = new ListNode(1, nullptr);
  }

  p = fake.next;
  q = &fake;
  while (p) {
    auto *tmp = p->next;
    p->next = q;
    q = p;
    p = tmp;
  }
  fake.next->next = nullptr;
  return q;
}

int main(int argc, char **argv) {
  ListNode *l1 = new ListNode(8, new ListNode(9, new ListNode(9)));
  ListNode *l2 = new ListNode(2);
  auto *sum_list = addTwoNumbers(l1, l2);

  PrintList(sum_list);
}