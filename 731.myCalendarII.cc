#include <vector>
#include <utility>

#include <stdio.h>
#include <stdlib.h>

/// 112ms
/// Beats 81.43%of users with C++
/// 34.12MB
/// Beats 95.95%of users with C++
class MyCalendarTwo {
  using Range = std::pair<int,int>;
 public:

  bool book(int start, int end) {
    for(auto& d : doubled_) {
      auto t = intersect({start, end}, d);
      if (t.first != -1) return false;
    }

    for(auto& ori : origins_){
      auto t = intersect({start, end}, ori);
      if (t.first != -1) {
        doubled_.push_back(t);
      }
    }

    origins_.push_back({start, end});
    return true;
  }

 private:
  std::vector<Range> origins_;
  std::vector<Range> doubled_;

  Range intersect(const Range& r1, const Range& r2) {
    Range r{-1,-1};
    if (r2.second <= r1.first || r2.first >= r1.second) {
      return {-1,-1};
    }
    if (r2.second >= r1.second && r2.first <= r1.first) {
      return r1;
    }
    if (r1.second >= r2.second && r1.first <= r2.first) {
      return r2;
    }

    if (r1.second > r2.second) {
      return {r1.first, r2.second};
    } else {
      return {r2.first, r1.second};
    }
  }
};

int main() {
  MyCalendarTwo c;
  printf("%d\n", c.book(47, 50));
  printf("%d\n", c.book(1, 10));
  printf("%d\n", c.book(27, 36));
  printf("%d\n", c.book(40, 47));
  printf("%d\n", c.book(20, 27));
  printf("%d\n", c.book(15, 23));
  printf("%d\n", c.book(10, 18));
  printf("%d\n", c.book(27, 36));
  printf("%d\n", c.book(17, 25));
  printf("%d\n", c.book(8, 17));
  printf("%d\n", c.book(24, 33));
  printf("%d\n", c.book(23, 28));
  printf("%d\n", c.book(21, 27));
  printf("%d\n", c.book(47, 50));
  printf("%d\n", c.book(14, 21));
  printf("%d\n", c.book(26, 32));
  printf("%d\n", c.book(16, 21));

}
