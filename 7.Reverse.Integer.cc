#include <cmath>
#include <limits>
#include <stdio.h>
#include <stdlib.h>

int reverse(int x) {
  bool is_negative = x < 0;
  long long ux = x;
  if (is_negative) {
    ux = -x;
  }
  int digit_len = 0;
  int factor = 1;
  while (ux > 0) {
    digit_len++;
    ux /= 10;
  }

  ux = x;
  if (is_negative) {
    ux = -x;
  }
  long long ret = 0;
  factor = 10;
  for (int i = 0; i < digit_len; i++) {
    ret += ux % (factor)*pow(10, digit_len - 1 - i);
    ux = ux / factor;
  }

  if (is_negative) {
    ret *= -1;
    if (ret < std::numeric_limits<int>::min()) {
      return 0;
    }
  } else {
    if (ret > 0x7fffffff) {
      return 0;
    }
  }

  return ret;

  // int iret = ret;
  // if ((ret < 0 && !is_negative) || (ret >= 0 && is_negative)) {
  //   return 0;
  // }
  // return (is_negative ? -1 : 1) * ret;
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
}