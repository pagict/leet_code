
#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (!list1) {
    return list2;
  }
  if (!list2) {
    return list1;
  }

  ListNode fake_head(0);
  ListNode *m = &fake_head;
  auto *p1 = list1;
  auto *p2 = list2;
  while (p1 && p2) {
    if (p2->val < p1->val) {
      m->next = p2;
      p2 = p2->next;
      m = m->next;
    } else {
      m->next = p1;
      p1 = p1->next;
      m = m->next;
    }
  }

  if (p1) {
    m->next = p1;
  } else {
    m->next = p2;
  }
  return fake_head.next;
}

void print_list(ListNode *lst) {
  auto *p = lst;
  while (p) {
    printf("[%d]", p->val);
    if (p->next) {
      printf("->");
    }
    p = p->next;
  }
  printf("\n");
}

int main(int argc, char **argv) {
  auto *p = new ListNode(3, new ListNode(5, new ListNode(8)));
  auto *q = new ListNode(1, new ListNode(2, new ListNode(8)));

  auto result = mergeTwoLists(p, q);
  print_list(result);
}