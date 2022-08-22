#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, std::vector<std::vector<int>>> cached_combs;

std::vector<std::vector<int>>
combinationSumInternal(std::vector<int> &candidates, int target) {
  std::vector<std::vector<int>> ret;
  if (target < candidates.front()) {
    return ret;
  }

  auto cache_iter = cached_combs.find(target);
  if (cache_iter != cached_combs.end() && !cache_iter->second.empty()) {
    return cache_iter->second;
  }

  for (auto i = 0u; i < candidates.size() && candidates[i] <= target; ++i) {
    auto candi = candidates[i];
    if (candi == target) {
      ret.push_back({target});
      break;
    }
    auto sub = combinationSumInternal(candidates, target - candi);
    for (auto &j : sub) {
      j.insert(std::upper_bound(j.begin(), j.end(), candi), candi);
      ret.push_back(j);
    }
  }
  cached_combs.emplace_hint(cache_iter, target, ret);
  return ret;
}

using Hash = struct Hash {
  std::size_t operator()(const std::vector<int> &vect) const {
    return vect.size();
  }
};

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                             int target) {
  std::vector<std::vector<int>> ret;
  std::sort(candidates.begin(), candidates.end());
  ret = combinationSumInternal(candidates, target);
  std::unordered_set<std::vector<int>, Hash> uniq(ret.begin(), ret.end(),
                                                  ret.size(), Hash());
  ret.assign(uniq.begin(), uniq.end());
  return ret;
}

void print_combinations(const std::vector<std::vector<int>> &combs) {
  printf("{");
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

int main(int argc, char **argv) {
  if (argc < 3) {
    return -1;
  }
  int target = std::atoi(argv[1]);
  std::vector<int> numbs;
  for (auto i = 2; i < argc; ++i) {
    numbs.push_back(std::atoi(argv[i]));
  }
  print_combinations(combinationSum(numbs, target));
  return 0;
}