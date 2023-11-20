#include <string>

/// 3ms
// Beats 88.22 % of users with C++
/// 6.62MB
// Beats 41.38 % of users with C++

std::string intToRoman(int num) {
  std::string ret;
  int m = num;

  struct {
    int value;
    char ch;
  } range_symbols[] = {
      {1, 'I'},   {5, 'V'},   {10, 'X'},   {50, 'L'},
      {100, 'C'}, {500, 'D'}, {1000, 'M'},
  };

  struct {
    int value;
    std::string symbol;
  } equal_symbols[] = {
      {4, "IV"},   {9, "IX"},   {40, "XL"},   {90, "XC"},
      {400, "CD"}, {900, "CM"}, {4000, "MK"},
  };

  int idx = sizeof(range_symbols) / sizeof(range_symbols[0]) - 1;

  while (m > 0) {

    bool prepend = false;
    if (equal_symbols[idx].value <= m) {
      ret.append(equal_symbols[idx].symbol);

      m -= equal_symbols[idx].value;

      prepend = true;
    }

    if (range_symbols[idx].value <= m) {
      int v = m / range_symbols[idx].value;
      for (int i = 0; v < 4 && i < v; ++i) {
        if (prepend) {
          ret.insert(0, 1, range_symbols[idx].ch);
        } else {
          ret.append(1, range_symbols[idx].ch);
        }
      }

      m -= range_symbols[idx].value * v;
    }

    --idx;
  }

  return ret;
}

int main(int argc, char **argv) {
  auto ret = intToRoman(std::atoi(argv[1]));
  printf("%s\n", ret.c_str());
  return 0;
}