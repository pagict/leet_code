#include <cstddef>
#include <cstdio>
#include <cstdlib>
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
  ListNode fake_head(0, head);
  auto *p = &fake_head;
  std::stack<ListNode *, std::vector<ListNode *>> node_stack;
  while (p) {
    ListNode *fast_p = p->next;
    for (auto i = 0u; i < k; ++i) {
      if (fast_p == nullptr) {
        return fake_head.next;
      }
      fast_p = fast_p->next;
    }

    auto *tmp = p->next;
    while (tmp != fast_p) {
      node_stack.push(tmp);
      tmp = tmp->next;
    }

    while (!node_stack.empty()) {
      auto *tmp = node_stack.top();
      node_stack.pop();
      p->next = tmp;
      p = tmp;
    }
    p->next = fast_p;
  }
  return fake_head.next;
}

void printList(ListNode *head) {
  if (!head) {
    return;
  }
  auto *p = head;
  while (p) {
    printf("%d", p->val);
    if (p->next) {
      printf("->");
    }
    p = p->next;
  }
  printf("\n");
}

int main(int argc, char **argv) {
  if (argc < 2) {
    return -1;
  }
  int k = std::atoi(argv[1]);
  ListNode fake_head(0);
  auto *p = &fake_head;
  for (auto i = 2u; i < argc; ++i) {
    p->next = new ListNode(std::atoi(argv[i]));
    p = p->next;
  }

  printList(reverseKGroup(fake_head.next, k));
}