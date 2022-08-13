#include <string>
#include <unordered_set>
#include <vector>

class MagicDictionary {
public:
  MagicDictionary() {}

  void buildDict(std::vector<std::string> dictionary) {
    for (auto i = 0u; i < dictionary.size(); ++i) {
      dicts_.insert(dictionary[i]);
    }
  }

  bool search(std::string searchWord) {
    for (auto iter = dicts_.begin(); iter != dicts_.end(); ++iter) {
      const auto &word = *iter;
      if (searchWord.length() != word.length()) {
        continue;
      }

      auto length = searchWord.length();
      auto diff_cnt = 0;
      auto i = 0u;
      for (i = 0u; i < length; ++i) {
        if (searchWord[i] != word[i]) {
          ++diff_cnt;
          if (diff_cnt > 1) {
            break;
          }
        }
      }
      if (i == length && diff_cnt == 1) {
        return true;
      }
    }
    return false;
  }

private:
  std::unordered_set<std::string> dicts_;
};
