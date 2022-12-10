#include <limits>
#include <string>

// Runtime 3ms, beats 87.65%
// Memory 7.1MB, beats 53.11%

int myAtoi(std::string s) {
  int v = 0;
  bool is_neg = false;
  auto i = 0;
  const auto kMax = std::numeric_limits<int>::max();
  const auto kMax31b = kMax / 10;
  const auto kMin = std::numeric_limits<int>::min();
  const auto kMin31b = kMin / 10;
  for (; i < s.size(); ++i) {
    if (s[i] != ' ') {
      break;
    }
  }

  if (s[i] == '-') {
    is_neg = true;
    ++i;
  } else if (s[i] == '+') {
    is_neg = false;
    ++i;
  }

  for (; i < s.size(); ++i) {
    if (s[i] > '9' || s[i] < '0') {
      break;
    }
    int num = s[i] - '0';
    if (!is_neg) {
      if (v > kMax31b) {
        return kMax;
      }
      v *= 10;
      if (kMax - num < v) {
        return kMax;
      }

      v += num;
    } else {
      if (v < kMin31b) {
        return kMin;
      }
      v *= 10;
      if (kMin + num > v) {
        return kMin;
      }
      v -= num;
    }
  }

  return v;
}

int main(int argc, char **argv) {
  std::string s("   ");
  if (argc > 1) {
    s.append(argv[1]);
  }
  printf("%d\n", myAtoi(s));
}