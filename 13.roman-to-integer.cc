#include <string>

int get_single(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;

  default:
    return 0;
    ;
  }
}

int romanToInt(std::string s) {
  int ret = 0;
  for (size_t i = 0; i < s.length(); ++i) {
    char c = s[i];

    int tmp = 0;
    if (i < s.length() - 1) {
      if ((c == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
          (c == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
          (c == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
        tmp = get_single(s[i + 1]) - get_single(c);
        ++i;
        ret += tmp;
        continue;
      }
    }
    ret += get_single(c);
  }

  return ret;
}

int main() {
  std::string x;
  x = "III";
  printf("romanToInt(%s)=%d\n", x.c_str(), romanToInt(x));

  x = "LVIII";
  printf("romanToInt(%s)=%d\n", x.c_str(), romanToInt(x));

  x = "MCMXCIV";
  printf("romanToInt(%s)=%d\n", x.c_str(), romanToInt(x));
}