#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>
int trapRainWater(std::vector<std::vector<int>> &heightMap) {
  auto m = heightMap.size();
  if (m < 3) {
    return 0;
  }
  auto n = heightMap[0].size();

  std::vector<std::vector<int>> savings{m, std::vector<int>(n, 0)};

  for (auto i = 0u; i < m; ++i) {
    const auto &row = heightMap[i];
    auto max_iter = std::max_element(row.begin(), row.end());
    auto max_idx = std::distance(row.begin(), max_iter);

    auto tmp_max_val = row.front();
    for (auto j = 0u; j < max_idx; ++j) {
      if (tmp_max_val > row[j]) {
        savings[i][j] = tmp_max_val - row[j];
      } else {
        tmp_max_val = row[j];
      }
    }

    tmp_max_val = row[n - 1];
    for (auto j = n - 1; j > max_idx; --j) {
      if (tmp_max_val > row[j]) {
        savings[i][j] = tmp_max_val - row[j];
      } else {
        tmp_max_val = row[j];
      }
    }
  }

  auto total = 0;
  for (auto i = 0; i < n; ++i) {
    auto max_idx = 0;
    for (auto j = 0u; j < m; ++j) {
      if (heightMap[j][i] > heightMap[max_idx][i]) {
        max_idx = j;
      }
    }

    auto tmp_max_val = heightMap[0][i];
    for (auto j = 0u; j < max_idx; ++j) {
      if (tmp_max_val > heightMap[j][i]) {
        auto res = tmp_max_val - heightMap[j][i];
        total += std::min(res, savings[j][i]);
      } else {
        tmp_max_val = heightMap[j][i];
        savings[j][i] = 0;
      }
    }
    tmp_max_val = heightMap[m - 1][i];
    for (auto j = m - 1; j > max_idx; --j) {
      if (tmp_max_val > heightMap[j][i]) {
        auto res = tmp_max_val - heightMap[j][i];
        total += std::min(res, savings[j][i]);
      } else {
        tmp_max_val = heightMap[j][i];
      }
    }
  }
  return total;
}

int main(int argc, char **argv) {
  std::vector<std::vector<int>> height_map;
  //   height_map = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3,
  //   1}}; printf("trapRainWater2D(...)=%d\n", trapRainWater(height_map));

  //   height_map = {{3, 3, 3, 3, 3},
  //                 {3, 2, 2, 2, 3},
  //                 {3, 2, 1, 2, 3},
  //                 {3, 2, 2, 2, 3},
  //                 {3, 3, 3, 3, 3}};
  //   printf("trapRainWater2D(...)=%d\n", trapRainWater(height_map));

  height_map = {{12, 13, 1, 12},
                {13, 4, 13, 12},
                {13, 8, 10, 12},
                {12, 13, 12, 12},
                {13, 13, 13, 13}};
  printf("trapRainWater2D(...)=%d\n", trapRainWater(height_map));
}