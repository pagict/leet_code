#include <cstdio>
#include <iterator>
#include <map>
#include <utility>
#include <vector>

int threeSumClosest(std::vector<int> &nums, int target) {
  std::sort(nums.begin(), nums.end());

  std::map<int, std::vector<std::pair<unsigned, unsigned>>> twoSumAndIdx;
  for (auto i = 0u; i < nums.size(); ++i) {
    for (auto j = i + 1; j < nums.size(); ++j) {
      twoSumAndIdx[nums[i] + nums[j]].push_back(std::make_pair(i, j));
    }
  }

  auto my_result = 99999;
  for (auto i = 0u; i < nums.size(); ++i) {
    auto target_sum = -nums[i] + target;
    auto lb_iter = twoSumAndIdx.lower_bound(target_sum);
    auto ub_iter = twoSumAndIdx.upper_bound(target_sum);

    auto &&valid_pair_idx = [i](const auto &sum_idx_lst) -> int {
      for (auto j = 0u; j < sum_idx_lst.size(); ++j) {
        if (sum_idx_lst[j].first != i && sum_idx_lst[j].second != i) {
          return j;
        }
      }
      return -1;
    };

    if (lb_iter != ub_iter && lb_iter != twoSumAndIdx.end()) {
      return target;
    }

    if (lb_iter == twoSumAndIdx.end()) {
      lb_iter = std::next(lb_iter, -1);
      ub_iter = lb_iter;
    }

    auto first_iter = twoSumAndIdx.begin();
    auto second_iter = first_iter;
    if (lb_iter != twoSumAndIdx.end() && ub_iter != twoSumAndIdx.end()) {
      if (std::abs(lb_iter->first + nums[i] - target) <
          std::abs(ub_iter->first) + nums[i] - target) {
        first_iter = lb_iter;
        second_iter = ub_iter;
      } else {
        first_iter = ub_iter;
        second_iter = lb_iter;
      }
    } else if (lb_iter != twoSumAndIdx.end()) {
      first_iter = lb_iter;
      second_iter = lb_iter;
    } else if (ub_iter != twoSumAndIdx.end()) {
      first_iter = ub_iter;
      first_iter = ub_iter;
    }

    auto tmp = 0;
    auto first_valid_idx = valid_pair_idx(first_iter->second);
    auto second_valid_idx = valid_pair_idx(second_iter->second);

    if (first_valid_idx >= 0) {
      tmp = first_iter->first + nums[i] - target;
    } else if (second_valid_idx >= 0) {
      tmp = second_iter->first + nums[i] - target;
    } else {
      continue;
    }

    if (tmp == 0) {
      return target;
    }
    if (std::abs(tmp) < std::abs(my_result)) {
      my_result = tmp;
    }
  }
  return my_result + target;
}

void print_result(const std::vector<int> &input, int target, int closet) {
  printf("threeSumCloset(%d, [", target);
  for (auto i = 0; i < input.size() - 1; ++i) {
    printf("%d,", input[i]);
  }
  printf("%d])=[%d", input[input.size() - 1], closet);
  printf("]\n");
}

int main(int argc, char **argv) {
  std::vector<int> input;

  input = {0, 1, 2};
  print_result(input, 0, threeSumClosest(input, 0));

  input = {0, 0, 0};
  print_result(input, 1, threeSumClosest(input, 1));

  input = {-1, 2, 1, -4};
  print_result(input, 1, threeSumClosest(input, 1));

  input = {-1, 2, 1, 4};
  print_result(input, 7, threeSumClosest(input, 7));

  input = {-4, -2, -1, 2, 3, 5, 5, 7, 10, 11};
  print_result(input, 3, threeSumClosest(input, 3));

  input = {-4, -2, -1, 2, 3, 5, 5, 7, 10, 11};
  print_result(input, 5, threeSumClosest(input, 5));

  input = {-4, -2, -1, 2, 3, 5, 5, 7, 10, 11};
  print_result(input, 25, threeSumClosest(input, 25));
}