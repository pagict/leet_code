#include <algorithm>
#include <iterator>
#include <vector>
using std::vector;

// Runtime: 10 ms, faster than 37.10% of C++ online submissions for Minimum Cost
// For Tickets.
// Memory Usage: 9.7 MB, less than 36.59% of C++ online submissions for Minimum
// Cost For Tickets.

int CostSinceDay(const vector<int> &days, const vector<int> &costs,
                 int min_cost_idx, vector<int> &cache, int day_idx) {
  if (day_idx >= days.size()) {
    return 0;
  }
  if (day_idx == days.size() - 1) {
    return costs[min_cost_idx];
  }

  auto &cache_val = cache[day_idx];
  if (cache_val != -1) {
    return cache_val;
  }

  auto c1 = CostSinceDay(days, costs, min_cost_idx, cache, day_idx + 1) +
            costs[min_cost_idx];

  auto idx = day_idx + 1;
  while (idx < days.size() && days[idx] - days[day_idx] < 7) {
    ++idx;
  }
  auto c2_idx = std::min<int>(days.size(), idx);
  auto c2 = c2_idx == (day_idx + 1)
                ? c1
                : CostSinceDay(days, costs, min_cost_idx, cache, c2_idx) +
                      (costs[1] < costs[2] ? costs[1] : costs[2]);

  while (idx < days.size() && days[idx] - days[day_idx] < 30) {
    ++idx;
  }
  auto c3_idx = std::min<int>(days.size(), idx);
  auto c3 = 0;
  if (c3_idx == c2_idx) {
    c3 = c2;
  } else if (c3_idx == day_idx) {
    c3 = c1;
  } else {
    c3 = CostSinceDay(days, costs, min_cost_idx, cache, c3_idx) + costs[2];
  }

  cache_val = std::min(c1, std::min(c2, c3));
  return cache_val;
}

int mincostTickets(vector<int> &days, vector<int> &costs) {
  std::vector<int> cache(days.size(), -1);
  auto min_idx = std::distance(costs.begin(),
                               std::min_element(costs.begin(), costs.end()));
  int cost = CostSinceDay(days, costs, min_idx, cache, 0);
  return cost;
}

int main(int argc, char **argv) {
  std::vector<int> costs;
  std::vector<int> days;
  for (auto i = 1; i <= 3; ++i) {
    costs.push_back(std::atoi(argv[i]));
  }
  for (auto i = 4; i < argc; ++i) {
    days.push_back(std::atoi(argv[i]));
  }

  printf("ret = %d\n", mincostTickets(days, costs));
}
