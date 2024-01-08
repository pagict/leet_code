#include <utility>
#include <vector>

// 510ms Beats 9.31 % of users with C++
// 40.65MB Beats 13.30 % of users with C++

class MyCalendarIII {
  typedef std::pair<int, int> Range;

public:
  MyCalendarIII() { overlapped_.reserve(400); }

  int book(int start, int end) {
    auto guest = std::make_pair(start, end);
    int count = 0;
    bool dup = false;
    auto last = overlapped_.size();
    for (auto i = 0; i < last; ++i) {
      auto &o = overlapped_[i];
      auto t = intersect(guest, o.first);
      if (t.first != -1) {
        count = count > (o.second + 1) ? count : o.second + 1;
        if (t.first == o.first.first && t.second == o.first.second) {
          ++(o.second);
          dup = true;
        } else {
          overlapped_.push_back({t, o.second + 1});
        }
      } else {
        count = count > o.second ? count : o.second;
      }
    }
    if (!dup) {
      overlapped_.push_back({guest, 1});
      count = count > 1 ? count : 1;
    }

    return count;
  }

private:
  std::vector<std::pair<Range, int>> overlapped_;

  Range intersect(const Range &r1, const Range &r2) {
    Range r{-1, -1};
    if (r2.second <= r1.first || r2.first >= r1.second) {
      return {-1, -1};
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
  MyCalendarIII c;
  printf("%d\n", c.book(28, 36));
  printf("%d\n", c.book(9, 16));
  printf("%d\n", c.book(71, 79));
  printf("%d\n", c.book(37, 43));
  printf("%d\n", c.book(88, 94));
  printf("%d\n", c.book(22, 29));
  printf("%d\n", c.book(95, 100));
  printf("%d\n", c.book(1, 7));
  printf("%d\n", c.book(40, 48));
  printf("%d\n", c.book(31, 39));
  printf("%d\n", c.book(5, 12));
  printf("%d\n", c.book(92, 100));
  printf("%d\n", c.book(54, 59));
  printf("%d\n", c.book(33, 41));
  printf("%d\n", c.book(2, 7));
  printf("%d\n", c.book(16, 25));
  printf("%d\n", c.book(57, 66));
  printf("%d\n", c.book(56, 61));
  printf("%d\n", c.book(63, 68));
  printf("%d\n", c.book(88, 93));
  printf("%d\n", c.book(99, 100));
  printf("%d\n", c.book(56, 65));
  printf("%d\n", c.book(5, 13));
  printf("%d\n", c.book(35, 42));
  printf("%d\n", c.book(69, 74));
  printf("%d\n", c.book(46, 51));
  printf("%d\n", c.book(39, 44));
  printf("%d\n", c.book(28, 36));
  printf("%d\n", c.book(78, 87));
  printf("%d\n", c.book(70, 79));
  printf("%d\n", c.book(91, 99));
  printf("%d\n", c.book(11, 19));
  printf("%d\n", c.book(41, 46));
  printf("%d\n", c.book(78, 87));
  printf("%d\n", c.book(67, 73));
  printf("%d\n", c.book(22, 31));
  printf("%d\n", c.book(4, 10));
  printf("%d\n", c.book(31, 40));
  printf("%d\n", c.book(54, 62));
  printf("%d\n", c.book(69, 76));
  printf("%d\n", c.book(36, 41));
  printf("%d\n", c.book(78, 84));
  printf("%d\n", c.book(40, 46));
  printf("%d\n", c.book(10, 18));
  printf("%d\n", c.book(4, 11));
  printf("%d\n", c.book(75, 84));
  printf("%d\n", c.book(86, 94));
  printf("%d\n", c.book(32, 40));
  printf("%d\n", c.book(34, 39));
  printf("%d\n", c.book(90, 99));
  printf("%d\n", c.book(8, 13));
  printf("%d\n", c.book(85, 93));
  printf("%d\n", c.book(24, 29));
  printf("%d\n", c.book(10, 17));
  printf("%d\n", c.book(10, 18));
  printf("%d\n", c.book(8, 17));
  printf("%d\n", c.book(1, 9));
  printf("%d\n", c.book(36, 45));
  printf("%d\n", c.book(42, 50));
  printf("%d\n", c.book(92, 97));
  printf("%d\n", c.book(22, 29));
  printf("%d\n", c.book(62, 67));
  printf("%d\n", c.book(70, 77));
  printf("%d\n", c.book(77, 86));
  printf("%d\n", c.book(74, 81));
  printf("%d\n", c.book(73, 78));
  printf("%d\n", c.book(47, 52));
  printf("%d\n", c.book(73, 80));
  printf("%d\n", c.book(24, 29));
  printf("%d\n", c.book(69, 75));
  printf("%d\n", c.book(69, 77));
  printf("%d\n", c.book(3, 9));
  printf("%d\n", c.book(34, 41));
  printf("%d\n", c.book(22, 27));
  printf("%d\n", c.book(3, 9));
  printf("%d\n", c.book(79, 88));
  printf("%d\n", c.book(34, 40));
  printf("%d\n", c.book(49, 56));
  printf("%d\n", c.book(42, 48));
  printf("%d\n", c.book(43, 52));
}