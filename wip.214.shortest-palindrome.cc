#include <string>

std::string shortestPalindrome(const std::string &s) {
  std::string ret;
  if (s.empty()) {
    return s;
  }
  if (s.length() == 2) {
    if (s[0] == s[1]) {
      return s;
    } else {
      ret.append(1, s[1]);
      ret.append(s);
      return ret;
    }
  }
  auto i = 0u;
  for (i = s.length() / 2; i >= 0; --i) {
    int p = i + 1;
    int q = i - 1;
    int r = i;
    while ((p < s.length() && q >= 0 && s[p] == s[q]) ||
           (r < s.length() && q >= 0 && s[r] == s[q])) {
      ++p;
      ++r;
      --q;
    }
    if (p >= s.length() || q < 0 || r >= s.length()) {
      break;
    }
  }

  auto length = s.length() - 1 - i - i;
  if (i > 0 && s[i] == s[i - 1]) {
    ++length;
  }
  for (auto j = s.length() - 1; j > s.length() - 1 - length && j >= 0; --j) {
    ret.append(1, s[j]);
  }
  ret.append(s);

  return ret;
}

int main(int argc, char **argv) {
  std::string s;
  if (argc == 2) {
    s = argv[1];
  }
  printf("shortestPalindrome(%s)=%s\n", s.c_str(),
         shortestPalindrome(s).c_str());
}