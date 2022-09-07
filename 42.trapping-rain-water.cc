#include <algorithm>
#include <iterator>
#include <vector>

// Runtime: 34 ms, faster than 22.75% of C++ online submissions for Trapping
// Rain Water. Memory Usage: 19.8 MB, less than 82.13% of C++ online submissions
// for Trapping Rain Water.

int trap(const std::vector<int> &height) {
  int res = 0;
  auto max_iter = std::max_element(height.begin(), height.end());
  auto max_riter = std::reverse_iterator<decltype(max_iter)>(max_iter);

  auto tmp_max_iter = height.begin();
  for (auto iter = height.begin(); iter != max_iter; ++iter) {
    if (*tmp_max_iter > *iter) {
      res += (*tmp_max_iter - *iter);
    } else if (*tmp_max_iter < *iter) {
      tmp_max_iter = iter;
    }
  }

  auto tmp_max_riter = height.rbegin();
  for (auto iter = height.rbegin(); iter != max_riter; ++iter) {
    if (*tmp_max_riter > *iter) {
      res += (*tmp_max_riter - *iter);
    } else if (*tmp_max_riter < *iter) {
      tmp_max_riter = iter;
    }
  }

  return res;
}

int main(int argc, char **argv) {
  std::vector<int> height;
  if (argc > 1) {
    for (auto i = 1u; i < argc; ++i) {
      height.push_back(std::atoi(argv[i]));
    }
  }

  printf("trap(...)=%d\n", trap(height));
}