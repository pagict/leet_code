#include <cstdio>
#include <cstdlib>
using ListNode = struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Runtime: 1243 ms, faster than 20.44% of C++ online submissions for Swapping
// Nodes in a Linked List.
// Memory Usage: 179.6 MB, less than 99.77% of C++ online submissions for
// Swapping Nodes in a Linked List.

ListNode *swapNodes(ListNode *head, int k) {
  ListNode fake_head(0, head);
  auto *before_pos_k = &fake_head;

  for (auto i = 0; i < k - 1; ++i) {
    before_pos_k = before_pos_k->next;
  }
  auto *tmp_fast = before_pos_k;
  auto *before_neg_k = &fake_head;

  while (tmp_fast->next && tmp_fast->next->next) {
    tmp_fast = tmp_fast->next;
    before_neg_k = before_neg_k->next;
  }

  if (before_pos_k->next != before_neg_k->next) {
    auto *pos_k = before_pos_k->next;
    auto *neg_k = before_neg_k->next;
    before_pos_k->next = neg_k;
    before_neg_k->next = pos_k;
    auto *tmp = neg_k->next;
    neg_k->next = pos_k->next;
    pos_k->next = tmp;
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

  printList(swapNodes(fake_head.next, k));
}