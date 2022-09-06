#include <algorithm>
#include <iterator>
#include <vector>

int trapInRange(const std::vector<int> &heights,
                const std::vector<int>::const_iterator max_iter,
                const std::vector<int>::const_iterator beg_iter,
                const std::vector<int>::const_iterator end_iter) {
  if (beg_iter >= end_iter || end_iter >= heights.end()) {
    return 0;
  }
  auto res = 0;
  if (std::distance(beg_iter, max_iter) > 1) {
    auto left_max_iter = std::max_element(beg_iter, max_iter);
    auto top = *left_max_iter;
    for (auto iter = left_max_iter; iter != max_iter; ++iter) {
      res += (top - *iter);
    }

    if (std::distance(beg_iter, left_max_iter) > 2) {
      res += trapInRange(heights, left_max_iter, beg_iter, max_iter);
    }
  }
  auto right_max_iter = std::max_element(std::next(max_iter), end_iter);
  for (auto iter = std::next(max_iter); iter != right_max_iter; ++iter) {
    res += (*right_max_iter - *iter);
  }
  if (std::distance(right_max_iter, end_iter) > 2) {
    res += trapInRange(heights, const std::vector<int>::const_iterator max_iter,
                       const std::vector<int>::const_iterator beg_iter,
                       const std::vector<int>::const_iterator end_iter)
  }

  return res;
}

int trap(const std::vector<int> &height) {
  int res = 0;
  enum Direction {
    kClimb = 0,
    kSlope = 1,
    kHorizontal = 2
  } direction = kHorizontal;

  auto prev_top_idx = 0u;
  for (auto i = 1u; i < height.size(); ++i) {
    auto d = (height[i] > height[i - 1]
                  ? kClimb
                  : (height[i] == height[i - 1] ? kHorizontal : kSlope));
    switch (d) {
    case kClimb: {
      if (direction != d) {
        direction = d;
      }
    } break;

    case kSlope: {
      if (direction != d) {
        auto tmp_height = std::min(height[i - 1], height[prev_top_idx]);
        for (auto j = prev_top_idx; j < i; ++j) {
          if (height[j] >= tmp_height) {
            continue;
          }

          res += (tmp_height - height[j]);
        }

        direction = d;
        prev_top_idx = i - 1;
      }
    }
    case kHorizontal:
      break;
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