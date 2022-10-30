#include <algorithm>
#include <vector>

// Runtime: 6 ms, faster than 67.99% of C++ online submissions for 2 Keys
// Keyboard. Memory Usage: 6 MB, less than 57.69% of C++ online submissions for
// 2 Keys Keyboard.

int MinSteps(int n, int current, int clipboard) {
  if (n == current) {
    return 0;
  }
  if (n == current + clipboard) {
    return 1;
  }
  if (current > n || current + clipboard > n) {
    return n;
  }
  int val = n;

  int a = MinSteps(n, current * 2, current);
  val = std::min(val, a + 2);

  int b = n;
  if (clipboard > 0) {
    b = MinSteps(n, current + clipboard, clipboard) + 1;
  }
  val = std::min(val, b);
  return val;
}

int minSteps(int n) {
  int ret = MinSteps(n, 1, 0);
  return ret;
}

int main(int argc, char **argv) {
  printf("ret = %d\n", minSteps(std::atoi(argv[1])));
}