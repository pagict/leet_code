#include <string>
#include <unordered_set>

class Trie {
public:
  Trie() {}

  void insert(std::string word) { words_.insert(word); }

  bool search(std::string word) { return words_.count(word) > 0; }

  bool startsWith(std::string prefix) {
    for (auto iter = words_.begin(); iter != words_.end(); ++iter) {
      auto sz = prefix.size();
      auto word_sz = iter->size();
      if (word_sz < sz) {
        continue;
      }
      auto i = 0u;
      for (i = 0u; i < sz; ++i) {
        if (iter->at(i) != prefix[i]) {
          break;
        }
      }

      if (i == sz) {
        return true;
      }
    }

    return false;
  }

private:
  std::unordered_set<std::string> words_;
};