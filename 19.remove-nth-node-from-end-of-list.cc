#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (!head || !n) {
    return nullptr;
  }
  ListNode fake_head(0, head);
  auto tail = head->next;
  while (--n > 0) {
    tail = tail->next;
  }

  auto prev = &fake_head;
  while (tail) {
    prev = prev->next;
    tail = tail->next;
  }
  prev->next = prev->next->next;
  return fake_head.next;
}

void print(ListNode *head) {
  auto node = head;
  while (node) {
    printf("%d", node->val);
    node = node->next;
    if (node) {
      printf("->");
    }
  }

  printf("\n");
}

int main(int argc, char **argv) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  print(head = removeNthFromEnd(head, 2));
  print(head = removeNthFromEnd(head, 4));
  print(head = removeNthFromEnd(head, 1));
  print(head = removeNthFromEnd(head, 2));
  print(head = removeNthFromEnd(head, 1));
  print(head = removeNthFromEnd(head, 0));
}