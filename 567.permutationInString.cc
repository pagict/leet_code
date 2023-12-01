#include <cstring>
#include <string>

using std::string;

// 4ms Beats 80.37 % of users with C++
// 7.67MB Beats 58.14 % of users with C++

bool checkInclusion(string s1, string s2) {
  int s1_counter[26] = {};
  for (auto c : s1) {
    ++s1_counter[c - 'a'];
  }

  int s2_counter[26] = {};
  int i = 0;
  int begin = 0;
  while (i < s2.length()) {
    int cnt_idx = s2[i] - 'a';
    ++s2_counter[cnt_idx];

    if (s1_counter[cnt_idx] == 0 || s1_counter[cnt_idx] < s2_counter[cnt_idx]) {
      int j = begin;
      while (j <= i && s2[j] != s2[i]) {
        int tmp = s2[j] - 'a';
        --s2_counter[tmp];
        ++j;
      }

      begin = j + 1;
      --s2_counter[s2[i] - 'a'];
    }

    if (i - begin + 1 == s1.length()) {
      return true;
    }

    ++i;
  }
  return false;
}

int main(int argc, char **argv) {
  printf("%d\n", checkInclusion(argv[1], argv[2]));
}