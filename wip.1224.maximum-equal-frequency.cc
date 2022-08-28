#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
int maxEqualFreq(const std::vector<int> &nums) {
  std::unordered_map<int, unsigned> num_freqs;
  if (nums.empty()) {
    return 0;
  }

  for (auto i = 0u; i < nums.size() - 1; ++i) {
    ++num_freqs[nums[i]];
  }
  std::unordered_map<unsigned, std::unordered_set<int>> num_freq_dist;
  for (auto &num_freq : num_freqs) {
    num_freq_dist[num_freq.second].insert(num_freq.first);
  }

  for (auto i = nums.size() - 1; i >= 0; --i) {
    auto num = nums[i];
    auto &current_freq = num_freqs[num];
    auto more_freq_set_iter = num_freq_dist.find(current_freq);
    more_freq_set_iter->second.erase(num);
    if (more_freq_set_iter->second.empty()) {
      num_freq_dist.erase(more_freq_set_iter);
      more_freq_set_iter = num_freq_dist.end();
    }
    --current_freq;
    auto less_freq_set_iter = num_freq_dist.end();
    if (current_freq > 0) {
      less_freq_set_iter = num_freq_dist.find(current_freq);
      less_freq_set_iter->second.insert(num);
    }
    if (num_freq_dist.size() != 2) {
      continue;
    }

    if (less_freq_set_iter != num_freq_dist.end()) {
    }
  }
  return nums.size();
}

void print_result(const std::vector<int> &input) {
  printf("maxEqualFreq(");
  if (input.empty()) {
    printf(")=");
  } else {
    for (auto i = 0u; i < input.size() - 1; ++i) {
      printf("%d, ", input[i]);
    }
    printf("%d)=", input.back());
  }
  printf("%d\n", maxEqualFreq(input));
}

int main(int argc, char **argv) {
  print_result({10, 9, 3, 5, 4, 3, 7, 9, 9});
  print_result({9, 9, 9, 5, 4, 9, 7, 9, 9});
  print_result({2, 2, 1, 1, 5, 3, 3, 5});
  return 0;
}