#include <string>
int isPrefixOfWord(const std::string &sentence, const std::string &searchWord) {
  auto word_idx = 0;
  auto i = 0u;
  while (i < sentence.size()) {
    auto c = sentence[i++];
    if (c == ' ' || i == 1) {
      ++word_idx;
      if (i == 1) {
        i = 0;
      }
      auto j = 0u;
      for (j = 0; j < searchWord.size(); ++j, ++i) {
        if (sentence[i] != searchWord[j]) {
          break;
        }
      }
      if (j == searchWord.size()) {
        return word_idx;
      }
      if (i == 0) {
        ++i;
      }
    }
  }
  return -1;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    return -1;
  }
  std::string sentence(argv[2]);
  for (auto i = 3; i < argc; ++i) {
    sentence.append(1, ' ');
    sentence.append(argv[i]);
  }

  printf("isPrefixOfWord(%s, \"%s\")=%d\n", argv[1], sentence.c_str(),
         isPrefixOfWord(sentence, argv[1]));
}