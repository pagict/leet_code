#include <cmath>
#include <limits>
#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
  if (x == std::numeric_limits<int>::min()) {
    return 0;
  }
  bool is_negative = x < 0;
  unsigned ux = x;
  if (is_negative) {
    ux = (~x) + 1;
  }
  int digit_len = 0;
  int factor = 1;
  while (ux > 0) {
    digit_len++;
    ux /= 10;
  }

  ux = x;
  if (is_negative) {
    ux = (~x) + 1;
  }

  if (digit_len > 9 && (ux % 10) > 2) {
    return 0;
  }

  unsigned ret = 0;
  factor = 10;
  for (int i = 0; i < digit_len; i++) {
    unsigned tmp = ux % (factor)*pow(10, digit_len - 1 - i);
    if (std::numeric_limits<int>::max() - ret < tmp) {
      return 0;
    }
    ret += ux % (factor)*pow(10, digit_len - 1 - i);
    ux = ux / factor;
  }

  if (is_negative) {
    ret *= -1;
  } else {
    if (ret > 0x7fffffff) {
      return 0;
    }
  }

  return ret;
}

int main(int argc, char **argv) {
  int x = 565;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = std::numeric_limits<int>::min();
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = 23463;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = -231;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = 0;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = -1;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = 1534236469;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = std::numeric_limits<int>::max();
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = -2147483648;
  printf("reverse(%d) = %d\n", x, reverse(x));

  x = 1534236461;
  printf("reverse(%d) = %d\n", x, reverse(x));
}
