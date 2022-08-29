#include <vector>

std::vector<std::vector<int>> combineInternal(std::vector<int> &result,
                                              std::vector<int> available) {
  std::vector<std::vector<int>> ret;
  for (auto i : available) {
    auto tmp_ret = result;
    tmp_ret.push_back(i);
    available.erase()
  }
}

std::vector<std::vector<int>> combine(int n, int k) {
  std::vector<std::vector<int>> ret;
  std::vector<int> selected(k, 0);

  for (auto i = 0u; i < k; ++i) {
  }

  return ret;
}

void print_combinations(const std::vector<std::vector<int>> &combs) {
  printf("%lu{", combs.size());
  if (combs.empty()) {
    printf("}\n");
    return;
  }
  auto &&print_one_comb = [](const auto &comb) {
    printf("{");
    if (comb.empty()) {
      printf("}");
      return;
    }
    for (auto i = 0u; i < comb.size() - 1; ++i) {
      printf("%d, ", comb[i]);
    }
    printf("%d}", comb[comb.size() - 1]);
  };
  for (auto i = 0u; i < combs.size() - 1; ++i) {
    print_one_comb(combs[i]);
    printf(", ");
  }
  print_one_comb(combs.back());
  printf("}\n");
}

int main(int argc, char **argv) {}