#include <vector>
int busyStudent(const std::vector<int> &startTime,
                const std::vector<int> &endTime, int queryTime) {
  int cnt = 0;
  for (auto i = 0u; i < startTime.size(); ++i) {
    if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
      ++cnt;
    }
  }
  return cnt;
}