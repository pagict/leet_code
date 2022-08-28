#include <cstdio>
#include <cstdlib>
using ListNode = struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// speed: 24.15%
// mem: 7.6MB, 54.55%

ListNode *swapPairs(ListNode *head) {
  if (!head) {
    return head;
  }
  ListNode fake_head(0, head);
  auto *p = (fake_head.next);
  auto *q = (p)->next;
  auto prev = &fake_head;
  while (p && q) {
    prev->next = q;
    p->next = q->next;
    q->next = p;
    prev = p;
    p = p->next;
    if (p) {
      q = p->next;
    } else {
      q = nullptr;
    }
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
  ListNode fake_head(0);
  auto *p = &fake_head;
  for (auto i = 1u; i < argc; ++i) {
    p->next = new ListNode(std::atoi(argv[i]));
    p = p->next;
  }

  printList(swapPairs(fake_head.next));
}