#include <cstdio>
#include <vector>

// 15ms Beats 92.96 % of users with C++
// 17.11MB
// Beats 43.29 % of users with C++

class MyCircularQueue {
public:
  MyCircularQueue(int k) : buf_(k + 1, 0) {}

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    buf_[head_] = value;
    head_ = (head_ + 1) % buf_.size();
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    tail_ = (tail_ + 1) % buf_.size();
    return true;
  }

  int Front() {
    if (isEmpty()) {
      return -1;
    }
    return buf_[tail_];
  }

  int Rear() {
    if (isEmpty()) {
      return -1;
    }
    if (head_ > 0) {
      return buf_[head_ - 1];
    }
    return buf_[buf_.size() - 1];
  }

  bool isEmpty() { return head_ == tail_; }

  bool isFull() { return (head_ + 1) % (buf_.size()) == tail_; }

private:
  int head_ = 0;
  int tail_ = 0;
  std::vector<int> buf_;
};

int main() {
  MyCircularQueue mcq(3);
  printf("%d\n", mcq.enQueue(1));
  printf("%d\n", mcq.enQueue(2));
  printf("%d\n", mcq.enQueue(3));
  printf("%d\n", mcq.enQueue(4));
  printf("%d\n", mcq.isFull());
  printf("%d\n", mcq.deQueue());
  printf("%d\n", mcq.enQueue(4));
  printf("%d\n", mcq.Rear());
}