#include <cmath>
#include <unordered_map>
#include <vector>

unsigned f(int x) {
  auto res = x / 5;
  std::vector<unsigned long long> pows{1};
  while (pows.back() <= x) {
    auto res = pows.back() * 5;
    if (res > x) {
      break;
    }
    pows.push_back(res);
  }

  for (auto i = 5u; i <= x; i += 5) {
    auto num = i;
    for (auto j = pows.size() - 1; j > 0; --j) {
      if (num < pows[j]) {
        continue;
      }

      if (num % pows[j] == 0) {
        res += (j - 1);
        num = num / pows[j];
      }
    }
  }

  // printf("f(%d)=%d\n", x, res);
  return res;
}

int preimageSizeFZF(int k) {
  int x = k * 3;
  // x = 0;
  while (true) {
    auto res = f(x);
    if (res == k) {
      printf("f(%d)=%d\n", x, k);
      return 5;
    } else if (res > k) {
      return 0;
    }
    x += 5;
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    return -1;
  }
  int k = std::atoi(argv[1]);
  printf("f(%d)=%d\n", k, f(k));
  printf("result: %d\n", preimageSizeFZF(k));
  return 0;
}