#include <stack>
#include <vector>
using ListNode = struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k) {
  auto *fast_p = head;
  for (auto i = 0u; i < k; ++i) {
    if (fast_p == nullptr) {
      return head;
    }
    fast_p = fast_p->next;
  }

  ListNode fake_head(0, head);
  auto *p = head;
  std::stack<ListNode *, std::vector<ListNode *>> node_stack;
  while (p) {
    auto *tmp = p;
    while (tmp != fast_p) {
      node_stack.push(tmp);
      tmp = tmp->next;
    }
  }
  return nullptr;
}