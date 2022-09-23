
#include "leetcode_common_struct.h"

// Runtime: 108 ms, faster than 11.57% of C++ online submissions for Reorder
// List.
// Memory Usage: 17.8 MB, less than 77.33% of C++ online submissions for Reorder
// List.

void reorderList(ListNode *head) {
  ListNode fake_head(0, head);
  auto *fast = &fake_head;
  auto *slow = &fake_head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next;
    if (fast) {
      fast = fast->next;
    }
  }

  auto *rev = slow;
  auto *next_rev = slow->next;
  slow->next = nullptr;
  while (next_rev) {
    auto *tmp = next_rev->next;
    next_rev->next = rev;

    rev = next_rev;
    next_rev = tmp;
  }

  auto *p = head;
  while (p) {
    auto *tmp = p->next;
    p->next = rev;
    rev = rev->next;
    p->next->next = tmp;
    p = tmp;
  }
}

int main(int argc, char **argv) {
  ListNode *head;
  head = new ListNode(
      1,
      new ListNode(
          2,
          new ListNode(
              3, new ListNode(4, new ListNode(5, new ListNode(6, nullptr))))));
  reorderList(head);
  PrintList(head);
}