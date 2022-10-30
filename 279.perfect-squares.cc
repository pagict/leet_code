#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

// Runtime: 875 ms, faster than 11.22% of C++ online submissions for Perfect
// Squares. Memory Usage: 40.9 MB, less than 12.90% of C++ online submissions
// for Perfect Squares.

std::unordered_map<int, int> cache;

int numSquares(int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n < 0) {
    return -1;
  }
  auto iter = cache.find(n);
  if (iter != cache.end()) {
    return iter->second;
  }
  int k = std::sqrt(n) + 1;
  int min = -1;
  for (auto i = k; i > 0; --i) {
    int a = numSquares(n - i * i);
    if (a == -1) {
      continue;
    }

    if (min == -1 || (a + 1) < min) {
      min = a + 1;
    }
    if (a == 0) {
      break;
    }
  }
  cache.insert(std::make_pair(n, min));
  return min;
}

int main(int argc, char **argv) {
  printf("ret = %d\n", numSquares(std::atoi(argv[1])));
}