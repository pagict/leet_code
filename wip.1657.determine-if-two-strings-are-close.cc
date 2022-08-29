#include <string>
#include <unordered_map>

bool closeStrings(const std::string &word1, const std::string &word2) {
  if (word1.length() != word2.length()) {
    return false;
  }

  std::unordered_map<char, unsigned> ch_cnt1;
  std::unordered_map<char, unsigned> ch_cnt2;

  for (auto i = 0u; i < word1.length(); ++i) {
    ++ch_cnt1[word1[i]];
    ++ch_cnt2[word2[i]];
  }

  for (auto iter1 = ch_cnt1.begin(); iter1 != ch_cnt1.end();) {
    auto iter2 = ch_cnt2.find(iter1->first);
    if (iter2 != ch_cnt2.end() && iter2->second == iter1->second) {
      ch_cnt2.erase(iter2);
      iter1 = ch_cnt1.erase(iter1);
    } else {
      ++iter1;
    }
  }

  return false;
}