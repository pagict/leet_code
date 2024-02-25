#include <algorithm>
#include <functional>
#include <vector>
int halveArray(std::vector<int> &nums) {
  std::vector<float> sorted;
  sorted.reserve(nums.size());
  double init_sum = 0;
  for (auto &n : nums) {
    sorted.push_back(n);
    init_sum += n;
    std::push_heap(sorted.begin(), sorted.end(), std::less<float>());
  }

  int c = 0;
  double sum = init_sum;
  while (true) {
    std::pop_heap(sorted.begin(), sorted.end(), std::less<float>());
    sorted.back() /= 2;
    sum -= sorted.back();
    ++c;
    if (sum <= init_sum / 2) {
      break;
    }

    std::push_heap(sorted.begin(), sorted.end(), std::less<float>());
  }
  return c;
}

int main(int argc, char **argv) {
  std::vector<int> nums;
  for (auto i = 1; i < argc; ++i) {
    nums.push_back(atoi(argv[i]));
  }
  printf("%d\n", halveArray(nums));
  return 0;
}