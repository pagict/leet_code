#include <array>
#include <string>
#include <unordered_set>
#include <vector>

int uniqueMorseRepresentations(std::vector<std::string> &words) {
  const static std::array<std::string, 26> kMorisBook = {
      ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
      ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
      "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

  std::unordered_set<std::string> transformations;

  std::string tmp_transf;
  for (const auto &word : words) {
    tmp_transf.clear();
    for (const auto c : word) {
      tmp_transf.append(kMorisBook[c - 'a']);
    }
    transformations.insert(tmp_transf);
  }
  return transformations.size();
}

int main(int argc, char **argv) {
  std::vector<std::string> words;
  words = {"gin", "zen", "gig", "msg"};
  printf("ret=%d\n", uniqueMorseRepresentations(words));
}