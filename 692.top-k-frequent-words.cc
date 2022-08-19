#include <algorithm>
#include <cstdio>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> topKFrequent(std::vector<std::string> &words, int k) {
  std::vector<std::string> ret;
  ret.reserve(k);

  std::unordered_map<std::string, unsigned> counts;
  for (const auto &w : words) {
    ++counts[w];
  }
  std::vector<std::unordered_map<std::string, unsigned>::iterator> heap;
  heap.reserve(counts.size());

  auto &&heap_comp = [](const auto &p1, const auto &p2) {
    if (p1->second < p2->second) {
      return true;
    }
    if (p1->second == p2->second) {
      return p1->first.compare(p2->first) > 0;
    }
    return false;
  };
  std::make_heap(heap.begin(), heap.end(), heap_comp);
  for (auto iter = counts.begin(); iter != counts.end(); ++iter) {
    heap.push_back(iter);
    std::push_heap(heap.begin(), heap.end(), heap_comp);
  }

  auto lenght = heap.size();
  for (auto i = 0u; i < k; ++i) {
    std::pop_heap(heap.begin(), std::prev(heap.end(), i), heap_comp);
    ret.push_back(heap[heap.size() - 1 - i]->first);
  }
  return ret;
}

void print(const std::vector<std::string> &input, unsigned k,
           const std::vector<std::string> &output) {
  printf("topKFrequent(");
  for (auto iter = input.begin(); iter != std::prev(input.end()); ++iter) {
    printf("%s, ", iter->c_str());
  }
  printf("%s), %u)=(", input.rbegin()->c_str(), k);
  for (auto iter = output.begin(); iter != std::prev(output.end()); ++iter) {
    printf("%s, ", iter->c_str());
  }
  printf("%s)\n", output.rbegin()->c_str());
}

int main(int argc, char **argv) {
  std::vector<std::string> words;
  words = {"the", "day", "is",    "sunny", "the",
           "the", "the", "sunny", "is",    "is"};
  auto k = 4u;
  print(words, k, topKFrequent(words, k));

  words = {"i", "love", "leetcode", "i", "love", "coding"};
  k = 2;
  print(words, k, topKFrequent(words, k));
}