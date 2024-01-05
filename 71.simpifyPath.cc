#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>

/// 3ms
/// Beats 91.41%of users with C++
/// 7.43MB
/// Beats 98.25%of users with C++
std::string simplifyPath(std::string path) {
  std::vector<std::pair<int, size_t>> components;

  int i = 0;
  int first = 0;
  while (i < path.size()) {
    char c = path[i];
    if (c == '/') {
      if (first <=i - 1) {
        components.push_back({first, i - first});
      }
      ++i;
      first = i;
      continue;
    }

    if (c == '.') {
      if (first < i) {
        ++i;
      } else {
        if (i+1 == path.size() || path[i+1] == '/') {
          i = i + 2;
          first = i;
          continue;
        }

        if (path[i+1] == '.') {
          if (i+2 == path.size() || path[i+2] == '/') {
            if (!components.empty()) {
              components.pop_back();
            }
            i = i + 3;
            first = i;
            continue;
          }

          i = i + 3;
        } else {
          i = i + 2;
        }
      }
    } else {
      ++i;
    }
  }
  if (i > first) {
    components.push_back({first, i - first});
  }

  int total_len = 0;
  for (const auto &c : components) {
    total_len += c.second;
  }
  total_len += components.size();
  if (!total_len) {
    total_len = 1;
  }
  std::string ret(total_len, '/');
  int offset = 1;
  for (const auto& c : components) {
    for (auto i = 0; i < c.second; ++i) {
      ret[offset + i] = path[c.first + i];
    }
    offset += c.second;
    ++offset;
  }
  return ret;
}

int main(int argc, char** argv) {
  std::vector<std::pair<std::string, std::string>> cases{
    {"/axb/sxd/sx", "/axb/sxd/sx"},
    {"/axx/.", "/axx"},
    {"/ax/./ssx", "/ax/ssx"},
    {"/a.x/x", "/a.x/x"},
    {"/asx/.s", "/asx/.s"},
    {"/xd/../sx/.", "/sx"},
    {"/sxx/.sd/../a", "/sxx/a"},
    {"/", ""},
    {"/.", "/"},
    {"/..", "/"},
    {"/sx/", "/sx"},
    {"/../", "/"},
    {"/a/./b/../../c/", "/c"},
    {"/home//s", "/home/s"},
    {"/home/", "/home"},
    {"/...", ""},
    {"/as..sdf", ""}
  };
  for(auto& c : cases) {
    auto tmp = simplifyPath(c.first);
    auto expect = c.second;
    if (expect.empty()) expect = c.first;
    if (tmp != expect) {
      std::cout << "!!! " << c.first << " -> " << tmp << std::endl;
    }
    else {
       std::cout << c.first << " -> " << tmp << std::endl;
    }
  }
  return 0;
}
