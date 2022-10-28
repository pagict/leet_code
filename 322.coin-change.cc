#include <algorithm>
#include <atomic>
#include <cstddef>
#include <unordered_map>
#include <utility>
#include <vector>

// Runtime: 822 ms, faster than 5.01% of C++ online submissions for Coin Change.
// Memory Usage: 66.3 MB, less than 5.19% of C++ online submissions for Coin
// Change.

std::unordered_map<int, int> cache;

int coinChangeCnt(const std::vector<int> &coins, int amount) {
  if (amount == 0) {
    return 0;
  }
  auto cache_iter = cache.find(amount);
  if (cache_iter != cache.end()) {
    return cache_iter->second;
  }

  auto min = -1;
  for (auto i = 0; i < coins.size(); ++i) {
    if (coins[i] > amount) {
      continue;
    }
    auto a = coinChangeCnt(coins, amount - coins[i]);
    if (a > 0) {
      ++a;
      if (min == -1 || a < min) {
        min = a;
      }
    }
  }
  cache[amount] = min;

  return min;
}

int coinChange(std::vector<int> &coins, int amount) {
  cache.clear();
  cache.reserve(coins.size());
  for (auto v : coins) {
    cache[v] = 1;
  }
  return coinChangeCnt(coins, amount);
}

int main(int argc, char **argv) {
  std::vector<int> coins;
  for (auto i = 2; i < argc; ++i) {
    coins.push_back(std::atoi(argv[i]));
  }
  printf("ret = %d\n", coinChange(coins, std::atoi(argv[1])));
  return 0;
}