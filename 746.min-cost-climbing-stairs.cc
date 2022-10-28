#include <vector>

// Runtime: 8 ms, faster than 79.42% of C++ online submissions for Min Cost
// Climbing Stairs.
// Memory Usage: 13.9 MB, less than 12.58% of C++ online submissions for Min
// Cost Climbing Stairs.

std::vector<int> cache;

int CostToTop(const std::vector<int> &costs, int current) {
  if (current >= costs.size()) {
    return 0;
  }
  if (current == costs.size() - 1) {
    return costs[current];
  }

  auto &cache_val = cache[current];
  if (cache_val > 0) {
    return cache_val;
  }

  int cost1 = CostToTop(costs, current + 1);
  int cost2 = CostToTop(costs, current + 2);
  cache_val = std::min(cost1, cost2) + costs[current];
  return cache_val;
}

int minCostClimbingStairs(std::vector<int> &cost) {
  cache = std::vector<int>(cost.size(), 0);
  int cost_from_0 = CostToTop(cost, 0);
  int cost_from_1 = CostToTop(cost, 1);
  return std::min(cost_from_0, cost_from_1);
}

int main(int argc, char **argv) {
  std::vector<int> costs;
  for (auto i = 1; i < argc; ++i) {
    costs.push_back(std::atoi(argv[i]));
  }
  printf("cost=%d\n", minCostClimbingStairs(costs));
}