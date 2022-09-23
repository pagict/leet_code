#include <vector>

#include "leetcode_common_struct.h"

// Runtime: 338 ms, faster than 15.77% of C++ online submissions for Merge k
// Sorted Lists.
// Memory Usage: 12.9 MB, less than 95.85% of C++ online submissions for Merge k
// Sorted Lists.

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  if (lists.empty()) {
    return nullptr;
  }
  auto *ret = lists[0];
  ListNode fake_head(0, ret);
  for (auto i = 1u; i < lists.size(); ++i) {
    auto *p = &fake_head;
    while (lists[i]) {
      while (p->next && p->next->val < lists[i]->val) {
        p = p->next;
      }

      auto *tmp = p->next;
      p->next = lists[i];
      lists[i] = lists[i]->next;
      p->next->next = tmp;
    }
  }
  return fake_head.next;
}

int main(int argc, char **argv) {
  std::vector<ListNode *> vec;
  vec.push_back(new ListNode(
      -8,
      new ListNode(9, new ListNode(10, new ListNode(12, new ListNode(20))))));
  vec.push_back(new ListNode(1, new ListNode(3)));
  vec.push_back(new ListNode(2, new ListNode(15)));

  PrintList(mergeKLists(vec));
}