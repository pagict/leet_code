#include <string>

int strStr(const std::string &haystack, const std::string &needle) {
  if (haystack.empty()) {
    return 0;
  }
  auto pos = haystack.find(needle);
  if (pos == std::string::npos) {
    return -1;
  }
  return pos;
}