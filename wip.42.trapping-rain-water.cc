#include <algorithm>
#include <iterator>
#include <vector>

int trapInRangeLeft(const std::vector<int> &heights,
                    const std::vector<int>::const_iterator beg_iter,
                    const std::vector<int>::const_iterator end_iter) {
  if (beg_iter >= end_iter || end_iter >= heights.end()) {
    return 0;
  }
  auto max_iter = std::max_element(beg_iter, end_iter);
  auto top = *max_iter;
  auto res = 0;
  for (auto iter = max_iter; iter != end_iter; ++iter) {
    res += (top - *iter);
  }

  if (std::distance(beg_iter, max_iter) > 1) {
    res += trapInRangeLeft(heights, beg_iter, max_iter);
  }
  return res;
}

int trapInRangeRight(const std::vector<int> &heights,
                     const std::vector<int>::const_iterator beg_iter,
                     const std::vector<int>::const_iterator end_iter) {
  if (beg_iter >= end_iter || end_iter > heights.end()) {
    return 0;
  }
  auto rbeg_iter = std::vector<int>::const_reverse_iterator(end_iter);
  auto rend_iter = std::vector<int>::const_reverse_iterator(beg_iter);
  auto rmax_iter = std::max_element(rbeg_iter, rend_iter);
  auto max_iter = std::prev(std::vector<int>::const_iterator(rmax_iter.base()));
  auto top = *rmax_iter;
  auto res = 0;
  for (auto iter = beg_iter; iter != max_iter; ++iter) {
    res += (top - *iter);
  }

  if (std::distance(max_iter, end_iter) > 1) {
    res += trapInRangeRight(heights, std::next(max_iter), end_iter);
  }
  return res;
}

int trap(const std::vector<int> &height) {
  int res = 0;

  auto max_iter = std::max_element(height.begin(), height.end());
  res += trapInRangeLeft(height, height.begin(), max_iter);
  res += trapInRangeRight(height, std::next(max_iter), height.end());
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