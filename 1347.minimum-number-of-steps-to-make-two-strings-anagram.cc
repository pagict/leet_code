#include <string>
#include <unordered_map>

int minSteps(const std::string &s, const std::string &t) {
  std::unordered_map<char, unsigned> str_s_cnt;
  std::unordered_map<char, unsigned> str_t_cnt;
  for (auto c : s) {
    ++str_s_cnt[c];
  }
  for (auto c : t) {
    ++str_t_cnt[c];
  }

  auto cnt = s.size();
  for (auto c_cnt : str_s_cnt) {
    auto t_cnt = str_t_cnt[c_cnt.first];
    cnt -= std::min(t_cnt, c_cnt.second);
  }
  return cnt;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    return -1;
  }

  printf("%d\n", minSteps(argv[1], argv[2]));
}
