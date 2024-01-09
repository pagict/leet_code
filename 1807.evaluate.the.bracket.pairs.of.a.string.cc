#include "leetcode_common_struct.h"
#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

// 394ms Beats 35.37 % of users with C++
// 86.41MB Beats 100.00 % of users with C++

int find_kv_index(const std::string key,
                  const std::vector<std::vector<std::string>> &knowledge) {
  int l = 0;
  int r = knowledge.size();
  while (l <= r && l < knowledge.size()) {
    int m = (l + r) / 2;
    int cmp = key.compare(knowledge[m][0]);
    if (cmp == 0) {
      return m;
    } else if (cmp < 0) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

string evaluate(string s, vector<vector<string>> &knowledge) {
  std::string ret;
  int len = s.size();
  for (const auto &kv : knowledge) {
    len += kv[1].size();
    len -= kv[0].size();
  }
  if (len < (int)s.size()) {
    len = s.size();
  }
  ret.reserve(len);

  std::sort(knowledge.begin(), knowledge.end(),
            [](const auto &kv1, const auto &kv2) { return kv1[0] < kv2[0]; });
  std::string tmp_key(10, ' ');
  size_t pos = 0;
  while (pos < s.size()) {
    int i = pos;
    while (i < s.size() && s[i] != '(')
      ++i;
    if (i == s.size()) {
      ret.append(s.data() + pos);
      pos = i;
    } else {
      ret.append(s.data() + pos, i - pos);
      int j = i + 1;
      while (j < s.size() && s[j] != ')')
        ++j;
      tmp_key.assign(s, i + 1, j - i - 1);
      int kv_idx = find_kv_index(tmp_key, knowledge);

      if (kv_idx >= 0) {
        ret.append(knowledge[kv_idx][1]);
      } else {
        ret.append(1, '?');
      }

      pos = j + 1;
    }
  }

  return ret;
}

int main(int argc, char **argv) {
  std::string s(argv[1]);
  std::vector<std::vector<std::string>> knowledge;
  for (int i = 2; i < argc; ++i) {
    if (i % 2 == 0) {
      knowledge.push_back({std::string(argv[i])});
    } else {
      knowledge.back().push_back(argv[i]);
    }
  }

  auto ret = evaluate(s, knowledge);
  printf("%s\n", ret.data());
}