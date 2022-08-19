#include <array>
#include <string>
#include <vector>

const std::array<std::string, 8> kNumMapping = {"abc", "def",  "ghi", "jkl",
                                                "mno", "pqrs", "tuv", "wxyz"};

std::vector<std::string> letterCombinations(const std::string &digits) {
  std::vector<std::string> ret;
  std::vector<unsigned> max_offsets(digits.size());
  auto &&max_offset = [](char c) { return kNumMapping[c - '2'].size(); };
  for (auto i = 0u; i < digits.size(); ++i) {
    max_offsets[i] = max_offset(digits[i]);
  }
  std::vector<unsigned> offsets(digits.size(), 0);

  std::string temp_comb;
  while (true) {
    temp_comb.clear();
    for (auto i = 0u; i < digits.size(); ++i) {
      temp_comb.append(1, kNumMapping[digits[i] - '2'][offsets[i]]);
    }
    if (!temp_comb.empty()) {
      ret.emplace_back(temp_comb);
    }
    int i = digits.size() - 1;
    for (i = digits.size() - 1; i >= 0; --i) {
      ++offsets[i];
      if (offsets[i] < max_offsets[i]) {
        break;
      }
      offsets[i] = 0;
    }
    if (i < 0) {
      break;
    }
  }
  return ret;
}

void print_combinations(const std::vector<std::string> &combs) {
  printf("%lu[", combs.size());
  if (combs.empty()) {
    printf("]\n");
    return;
  }
  for (auto i = 0u; i < combs.size() - 1; ++i) {
    printf("\"%s\", ", combs[i].c_str());
  }
  printf("\"%s\"]\n", combs.back().c_str());
}

int main(int argc, char **argv) {
  std::string numbers;
  if (argc == 2) {
    numbers = argv[1];
  }

  print_combinations(letterCombinations(numbers));
}