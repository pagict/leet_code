using ListNode = struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapNodes(ListNode *head, int k) {
  ListNode fake_head(0, head);
  auto *before_pos_k = &fake_head;
  for (auto i = 0u; i < k; ++k) {
    before_pos_k = before_pos_k->next;
  }
  auto *tmp_fast = before_pos_k->next;
  auto *before_neg_k = fake_head.next;

  while (tmp_fast) {
    tmp_fast = tmp_fast->next;
    before_neg_k = before_neg_k->next;
  }

  if (before_pos_k->next != before_neg_k->next) {
    auto *pos_k = before_pos_k->next;
    auto *neg_k = before_neg_k->next;
  }
  return fake_head.next;
}