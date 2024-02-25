bool divideArray(vector<int> &nums) {
  std::vector<int> cnts(501, 0);
  for (auto n : nums) {
    cnts[n]++;
  }

  for (auto c : cnts) {
    if (c % 2) {
      return false;
    }
  }

  return true;
}