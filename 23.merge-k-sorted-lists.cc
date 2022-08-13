#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  std::vector<ListNode *> tails(lists.size(), nullptr);
  for (auto i = 0u; i < lists.size(); ++i) {
    tails[i] = lists[i];
  }
  ListNode fake_head(0);
  auto *m = &fake_head;
  while (true) {
    unsigned min_idx = -1;
    int min = 99999;
    for (auto i = 0u; i < tails.size(); ++i) {
      if (tails[i] && tails[i]->val < min) {
        min_idx = i;
        min = tails[i]->val;
      }
    }

    if (min_idx == -1) {
      break;
    }
    m->next = tails[min_idx];
    m = m->next;
    tails[min_idx] = tails[min_idx]->next;
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
  std::vector<ListNode *> vec;
  vec.push_back(new ListNode(
      -8,
      new ListNode(9, new ListNode(10, new ListNode(12, new ListNode(20))))));
  //   vec.push_back(new ListNode(1, new ListNode(3)));
  //   vec.push_back(new ListNode(2));

  print_list(mergeKLists(vec));
}