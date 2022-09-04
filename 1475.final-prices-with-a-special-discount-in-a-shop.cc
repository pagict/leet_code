#include <cstdio>
#include <vector>

// Runtime: 14 ms, beats 15.15% submissions.
// Memory Usage : 9.9 MB, beats 81.72% submissions

std::vector<int> finalPrices(std::vector<int> &prices) {
  std::vector<int> ret(prices.size(), 0);
  auto min = prices.back();
  for (int i = 0u; i < prices.size(); ++i) {
    auto val = prices[i];
    auto discount = 0;
    for (auto j = i + 1; j < prices.size(); ++j) {
      if (prices[j] <= val) {
        discount = prices[j];
        break;
      }
    }
    ret[i] = val - discount;
  }
  return ret;
}

void print_vector(const std::vector<int> &vec) {
  if (vec.empty()) {
    printf("0[]\n");
    return;
  }
  printf("%lu[", vec.size());
  for (auto i = 0; i < vec.size() - 1; ++i) {
    printf("%d, ", vec[i]);
  }
  printf("%d]\n", vec.back());
}

int main(int argc, char **argv) {
  std::vector<int> vec;
  if (argc > 1) {
    for (auto i = 1; i < argc; ++i) {
      vec.push_back(std::atoi(argv[i]));
    }
  }
  print_vector(finalPrices(vec));
}