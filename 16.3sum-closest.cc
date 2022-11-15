#include <cstdio>
#include <limits>
#include <vector>

// Runtime: 101 ms, faster than 92.48% of C++ online submissions for 3Sum
// Closest.
// Memory Usage: 10.1 MB, less than 97.49% of C++ online submissions for 3Sum
// Closest.

int threeSumClosest(std::vector<int> &nums, int target) {
  std::sort(nums.begin(), nums.end());

  auto sum = 0;
  auto diff = std::numeric_limits<int>::max();
  for (auto i = 0; i < nums.size() - 2; ++i) {
    auto left = i + 1;
    auto right = nums.size() - 1;

    while (left < right) {
      auto this_sum = nums[i] + nums[left] + nums[right];
      auto gap = std::abs(target - this_sum);
      if (gap == 0) {
        return target;
      }
      if (gap < diff) {
        sum = this_sum;
        diff = gap;
      }

      if (this_sum < target) {
        ++left;
      } else {
        --right;
      }
    }
  }
  return sum;
}

int main(int argc, char **argv) {
  std::vector<int> input;

  input = {4, 0, 5, -5, 3, 3, 0, -4, -5};
  printf("= %d\n", threeSumClosest(input, -2));

  input = {0, 1, 2};
  printf("= %d\n", threeSumClosest(input, 0));

  input = {0, 0, 0};
  printf("= %d\n", threeSumClosest(input, 1));

  input = {-1, 2, 1, -4};
  printf("= %d\n", threeSumClosest(input, 1));

  input = {-1, 2, 1, 4};
  printf("= %d\n", threeSumClosest(input, 7));

  input = {-4, -2, -1, 2, 3, 5, 5, 7, 10, 11};
  printf("= %d\n", threeSumClosest(input, 3));

  input = {-4, -2, -1, 2, 3, 5, 5, 7, 10, 11};
  printf("= %d\n", threeSumClosest(input, 5));

  input = {-4, -2, -1, 2, 3, 5, 5, 7, 10, 11};
  printf("= %d\n", threeSumClosest(input, 25));

  input = {
      13,   252,  -87,  -431, -148, 387,  -290, 572,  -311, -721, 222,  673,
      538,  919,  483,  -128, -518, 7,    -36,  -840, 233,  -184, -541, 522,
      -162, 127,  -935, -397, 761,  903,  -217, 543,  906,  -503, -826, -342,
      599,  -726, 960,  -235, 436,  -91,  -511, -793, -658, -143, -524, -609,
      -728, -734, 273,  -19,  -10,  630,  -294, -453, 149,  -581, -405, 984,
      154,  -968, 623,  -631, 384,  -825, 308,  779,  -7,   617,  221,  394,
      151,  -282, 472,  332,  -5,   -509, 611,  -116, 113,  672,  -497, -182,
      307,  -592, 925,  766,  -62,  237,  -8,   789,  318,  -314, -792, -632,
      -781, 375,  939,  -304, -149, 544,  -742, 663,  484,  802,  616,  501,
      -269, -458, -763, -950, -390, -816, 683,  -219, 381,  478,  -129, 602,
      -931, 128,  502,  508,  -565, -243, -695, -943, -987, -692, 346,  -13,
      -225, -740, -441, -112, 658,  855,  -531, 542,  839,  795,  -664, 404,
      -844, -164, -709, 167,  953,  -941, -848, 211,  -75,  792,  -208, 569,
      -647, -714, -76,  -603, -852, -665, -897, -627, 123,  -177, -35,  -519,
      -241, -711, -74,  420,  -2,   -101, 715,  708,  256,  -307, 466,  -602,
      -636, 990,  857,  70,   590,  -4,   610,  -151, 196,  -981, 385,  -689,
      -617, 827,  360,  -959, -289, 620,  933,  -522, 597,  -667, -882, 524,
      181,  -854, 275,  -600, 453,  -942, 134};
  printf("= %d\n", threeSumClosest(input, -2805));
}