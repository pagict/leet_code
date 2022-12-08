#include <algorithm>
#include <string>
using std::string;

// Runtime 19ms, beats 83.64%
// Memory 7MB, beats 72.45%

string longestPalindrome(string s) {
  int begin = 0;
  int end = 1;
  for (auto i = 0; i < s.size(); ++i) {
    int l = i - 1;
    int r = i + 1;
    while (l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
      --l;
      ++r;
    }
    ++l;
    --r;
    if ((r + 1 - l) > (end - begin)) {
      begin = l;
      end = r + 1;
    }

    l = i;
    r = i + 1;
    while (l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
      --l;
      ++r;
    }
    ++l;
    --r;
    if ((r + 1 - l) > (end - begin)) {
      begin = l;
      end = r + 1;
    }
  }
  return s.substr(begin, end - begin);
}

int main(int argc, char **argv) {
  std::string s;
  if (argc > 1) {
    s = argv[1];
  }
  auto ret = longestPalindrome(s);
  printf("%s\n", ret.c_str());
}