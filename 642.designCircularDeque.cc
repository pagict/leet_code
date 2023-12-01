#include <vector>

// 24ms Beats 48.21 % of users with C++
// 16.99MB Beats 51.66 % of users with C++

class MyCircularDeque {
public:
  MyCircularDeque(int k) : buf_(k + 1, 0) {}

  bool insertFront(int value) {
    if (isFull())
      return false;
    if (head_ > 0) {
      --head_;
    } else {
      head_ = buf_.size() - 1;
    }
    buf_[head_] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull())
      return false;
    buf_[rear_] = value;
    rear_ = (rear_ + 1) % buf_.size();
    return true;
  }

  bool deleteFront() {
    if (isEmpty())
      return false;
    head_ = (head_ + 1) % buf_.size();
    return true;
  }

  bool deleteLast() {
    if (isEmpty())
      return false;
    if (rear_ > 0) {
      --rear_;
    } else {
      rear_ = buf_.size() - 1;
    }
    return true;
  }

  int getFront() {
    if (isEmpty()) {
      return -1;
    }
    return buf_[head_];
  }

  int getRear() {
    if (isEmpty()) {
      return -1;
    }
    if (rear_ > 0) {
      return buf_[rear_ - 1];
    }
    return buf_[buf_.size() - 1];
  }

  bool isEmpty() { return rear_ == head_; }

  bool isFull() { return (rear_ + 1) % buf_.size() == head_; }

private:
  std::vector<int> buf_;
  int rear_ = 0;
  int head_ = 0;
};

int main() {
  MyCircularDeque mcd(3);
  printf("%d\n", mcd.insertLast(1));
  printf("%d\n", mcd.insertLast(2));
  printf("%d\n", mcd.insertFront(3));
  printf("%d\n", mcd.insertFront(4));
  printf("%d\n", mcd.getRear());
  printf("%d\n", mcd.isFull());
  printf("%d\n", mcd.deleteLast());
  printf("%d\n", mcd.insertFront(4));
  printf("%d\n", mcd.getFront());
}