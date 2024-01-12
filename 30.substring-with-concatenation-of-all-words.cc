#include <algorithm>
#include <cstring>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

#include "leetcode_common_struct.h"

using std::string;
using std::vector;

// 835 ms Beats 65.86 % of users with C++
// 14.36 MB Beats 98.77 % of users with C++

int findWord(const std::vector<std::string> &sorted_words, const char *p) {
  int len = sorted_words[0].size();
  int l = 0;
  int r = sorted_words.size();
  while (l < r && l < sorted_words.size()) {
    int m = (l + r) / 2;
    int cmp_ret = strncmp(p, sorted_words[m].c_str(), len);
    if (cmp_ret == 0) {
      return m;
    }

    if (cmp_ret < 0) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

vector<int> findSubstring(string s, vector<string> &words) {
  vector<int> ret;
  if (words.empty()) {
    return ret;
  }
  ret.reserve(s.length());
  auto len = words.size() * words[0].size();
  if (s.length() < len) {
    return ret;
  }

  std::sort(words.begin(), words.end());
  std::vector<std::pair<int, int>> cmp0range(words.size(),
                                             std::pair<int, int>(-1, -1));
  int i = 0;

  while (i < words.size()) {
    int j = i + 1;
    while (j < words.size() &&
           strncmp(words[i].c_str(), words[j].c_str(), words[0].size()) == 0) {
      ++j;
    }
    for (int k = i; k < j; ++k) {
      cmp0range[k].first = i;
      cmp0range[k].second = j;
    }
    i = j;
  }

  auto ranges = cmp0range;
  for (auto i = 0; i < s.size() - len + 1; ++i) {
    ranges = cmp0range;
    int j = 0;
    for (j = 0; j < words.size(); j++) {
      int idx = findWord(words, s.data() + i + j * words[0].size());
      if (idx < 0) {
        break;
      }
      if (ranges[idx].first == ranges[idx].second) {
        break;
      }
      ++ranges[idx].first;
    }

    if (j == words.size()) {
      ret.push_back(i);
    }
  }
  return ret;
}

/// s='a'*10000, words=['a']*5000
int main(int argc, const char **argv) {
  std::string s(argv[1]);

  std::vector<std::string> words;
  for (int i = 2; i < argc; ++i) {
    words.push_back(argv[i]);
  }

  PrintVect(findSubstring(s, words));
}
