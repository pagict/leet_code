#include <string>
std::string removeDigit(const std::string &number, char digit) {
  std::string ret;
  ret.reserve(number.size() - 1);

  int idx = -1;
  int last_idx = -1;
  for (auto i = 0; i < number.size(); ++i) {
    if (number[i] == digit) {
      last_idx = i;
      if (i == number.size() - 1 || number[i + 1] > digit) {
        idx = i;
        break;
      }
    }
  }
  if (idx == -1) {
    idx = last_idx;
  }
  ret.append(number.begin(), number.begin() + idx);
  ret.append(number.begin() + idx + 1, number.end());
  return ret;
}

int main(int argc, char **argv) {
  printf("%s\n", removeDigit(argv[1], argv[2][0]).c_str());
  return 0;
}