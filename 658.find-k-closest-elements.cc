#include <algorithm>
#include <iterator>
#include <vector>

std::vector<int> findClosestElements(std::vector<int> &arr, int k, int x) {
  std::vector<int> ret;
  ret.reserve(k);
  std::vector<int> heap;
  heap.reserve(arr.size());
  auto &&heap_cmp = [x](const auto &p, const auto &q) {
    auto tmp_p = std::abs(x - p);
    auto tmp_q = std::abs(x - q);
    if (tmp_p > tmp_q) {
      return true;
    } else if (tmp_p == tmp_q) {
      return p > q;
    }
    return false;
  };
  for (auto n : arr) {
    heap.push_back(n);
    std::push_heap(heap.begin(), heap.end(), heap_cmp);
  }

  for (auto i = 0u; i < k; ++i) {
    std::pop_heap(heap.begin(), std::prev(heap.end(), i), heap_cmp);
    ret.push_back(*(std::prev(heap.end(), 1 + i)));
  }
  std::sort(ret.begin(), ret.end());
  return ret;
}

int main(int argc, char **argv) {
  if (argc <= 3) {
    return -1;
  }
  int k = std::atoi(argv[1]);
  int x = std::atoi(argv[2]);
  std::vector<int> arr;
  for (auto i = 3; i < argc; ++i) {
    arr.push_back(std::atoi(argv[i]));
  }
  const auto &ret = findClosestElements(arr, k, x);
  printf("findClosestElements(k=%d, x=%d, arr=...)=%lu(", k, x, ret.size());
  if (ret.empty()) {
    printf(")\n");
  } else {
    for (auto i = 0; i < ret.size() - 1; ++i) {
      printf("%d, ", ret[i]);
    }
    printf("%d)\n", ret.back());
  }
  return 0;
}