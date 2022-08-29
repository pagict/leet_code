#include <cstdio>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Runtime: 101 ms, faster than 91.97% of C++ online submissions for Maximum
// Equal Frequency. Memory Usage: 49.4 MB, less than 55.18% of C++ online
// submissions for Maximum Equal Frequency.

int maxEqualFreq(const std::vector<int> &nums) {
  if (nums.empty()) {
    return 0;
  }

  std::unordered_map<int, unsigned> num_freqs;
  for (auto i = 0u; i < nums.size(); ++i) {
    ++num_freqs[nums[i]];
  }
  std::map<unsigned, std::unordered_set<int>> num_freq_dist;
  for (auto &num_freq : num_freqs) {
    num_freq_dist[num_freq.second].insert(num_freq.first);
  }

  for (int i = nums.size() - 1; i >= 0; --i) {
    if (num_freq_dist.size() == 2) {
      if (num_freq_dist.begin()->first == 1 &&
          num_freq_dist.begin()->second.size() == 1) {
        return i + 1;
      } else if (num_freq_dist.rbegin()->first - num_freq_dist.begin()->first ==
                     1 &&
                 num_freq_dist.rbegin()->second.size() == 1) {
        return i + 1;
      }
    } else if (num_freq_dist.size() == 1) {
      if (num_freq_dist.begin()->first == 1 ||
          num_freq_dist.begin()->second.size() == 1) {
        return i + 1;
      }
    }

    auto num = nums[i];
    auto &freq = num_freqs[num];
    auto iter = num_freq_dist.find(freq);
    iter->second.erase(num);
    if (iter->second.empty()) {
      num_freq_dist.erase(iter);
    }
    --freq;
    if (freq > 0) {
      num_freq_dist[freq].insert(num);
    }
  }

  return 0;
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
  print_result({2, 2, 1, 1, 5, 3, 3, 5, 9});
  print_result({1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5});
  print_result({1, 2});
  print_result({1, 1});
  return 0;
}