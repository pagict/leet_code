#include <unordered_map>
#include <utility>
#include <vector>

#include <stdio.h>
#include <stdlib.h>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
  std::vector<std::vector<int>> ret;
  std::unordered_map<int, std::vector<std::pair<unsigned, unsigned>>>
      sum_combinations;

  for (unsigned i = 0; i < nums.size(); ++i) {
    for (unsigned j = i + 1; j < nums.size(); ++j) {
      auto less_num_idx = i;
      auto less_num = nums[i];
      if (nums[i] > nums[j]) {
        less_num_idx = j;
        less_num = nums[j];
      }

      auto &comb_list = sum_combinations[nums[i] + nums[j]];
      size_t k = 0;
      for (k = 0; k < comb_list.size(); ++k) {
        if (nums[comb_list[k].first] == less_num) {
          break;
        }
      }

      if (k == comb_list.size() || comb_list.size() == 0) {
        comb_list.push_back(std::make_pair(less_num_idx, i ^ j ^ less_num_idx));
      }
    }
  }

  std::vector<int> tmp;
  for (unsigned i = 0; i < nums.size(); ++i) {
    auto iter = sum_combinations.find(-nums[i]);
    if (iter == sum_combinations.end()) {
      continue;
    }

    const auto &combine_list = iter->second;
    for (unsigned j = 0; j < combine_list.size(); ++j) {

      if (i != combine_list[j].second && i != combine_list[j].first &&
          i < combine_list[j].first && i < combine_list[j].second) {
        tmp.clear();

        tmp.push_back(nums[i]);
        tmp.push_back(nums[combine_list[j].first]);
        tmp.push_back(-(nums[i] + nums[combine_list[j].first]));

        ret.emplace_back(tmp);
      }
    }
  }

  return ret;
}

void print(const std::vector<int> &input,
           const std::vector<std::vector<int>> &output) {
  printf("threeSum(");
  for (auto i = 0; i < input.size() - 1; ++i) {
    printf("%d,", input[i]);
  }
  printf("%d)=[", input[input.size() - 1]);

  if (output.size() == 0) {
    printf("]\n");
    return;
  }
  for (auto i = 0; i < output.size() - 1; ++i) {
    printf("[%d, %d, %d], ", output[i][0], output[i][1], output[i][2]);
  }
  auto i = output.size() - 1;
  printf("[%d, %d, %d]]\n", output[i][0], output[i][1], output[i][2]);
}

int main(int argc, char **argv) {
  std::vector<int> input;
  input = {-1, 0, 1, 2, -1, -4};
  auto ret = threeSum(input);

  print(input, ret);
}
