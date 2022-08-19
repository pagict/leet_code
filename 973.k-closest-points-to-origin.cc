#include <algorithm>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points,
                                       int k) {
  std::vector<std::vector<int>> ret;
  ret.reserve(k);

  std::vector<std::pair<unsigned, unsigned>> idx_distances_heap;
  idx_distances_heap.reserve(points.size());

  auto &&cmp = [](const auto &p1, const auto &p2) {
    return p1.second > p2.second;
  };

  auto sz = points.size();
  for (auto i = 0u; i < sz; ++i) {
    auto x = std::abs(points[i][0]);
    auto y = std::abs(points[i][1]);

    auto distance_square = x * x + y * y;

    idx_distances_heap.push_back(std::make_pair(i, distance_square));
    std::push_heap(idx_distances_heap.begin(), idx_distances_heap.end(), cmp);
  }

  for (auto i = 0u; i < k; ++i) {
    std::pop_heap(idx_distances_heap.begin(),
                  std::prev(idx_distances_heap.end(), i), cmp);
    ret.push_back(
        points[idx_distances_heap[idx_distances_heap.size() - 1 - i].first]);
  }
  return ret;
}

void print(const std::vector<std::vector<int>> &output_points) {
  printf("[");
  for (auto i = 0u; i < output_points.size() - 1; ++i) {
    printf("(%d,%d), ", output_points[i][0], output_points[i][1]);
  }
  printf("(%d, %d)]\n", output_points.back()[0], output_points.back()[1]);
}

int main(int argc, char **argv) {
  std::vector<std::vector<int>> points;
  points = {{3, 3}, {5, -1}, {-2, 4}};
  auto k = 2;
  printf("kCloset(k=%d)=", k);
  print(kClosest(points, k));
}
