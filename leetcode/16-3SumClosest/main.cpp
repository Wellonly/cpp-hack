
#include <bits/stdc++.h>
#include <vector>

#include "catch.hpp"

using namespace std;

class Solution {
public:
  int solve(const vector<int>& nums, const int tar) {
      int res = 0;
      uint diff = UINT32_MAX;
      auto s = nums.size();
      uint fq=0, fw=0, fe=0;
      if (s < 3) return 0;
      if (s == 3) return accumulate(nums.begin(), nums.end(), 0);
      for (uint q = 0; q < s-2; q++) {
        for (uint w = 1; w < s-1; w++) {
          for (uint e = 2; e < s; e++) {
            int sum = nums[q]+nums[w]+nums[e];
            uint tdiff = abs(tar-sum);
            if (!tdiff) {
              cout << "found equal for:" << tar << " @:" << q << ":" << w << ":" << e << endl;
              return tar;
            } else if (tdiff < diff) {
              res = sum;
              diff = tdiff;
              fq=q; fw=w; fe=e;
            }
      }}}
      cout << "found closest:" << res << " for:" << tar << " @:" << fq << ":" << fw << ":" << fe << endl;
      return res;
  }
};

TEST_CASE("16-3Sum-Closest", "[tests]")
{
    Solution solution;
    SECTION("Sample Input 1")
    {
      REQUIRE(solution.solve({1, 5}, 111) == 0);
    }
    SECTION("Sample Input 2")
    {
      REQUIRE(solution.solve({1, 5, 10}, 111) == 16);
    }
    SECTION("Sample Input 3")
    {
      REQUIRE(solution.solve({1, 5, 10, 34, 112, 120}, 125) == 126);
    }
    SECTION("Sample Input 4")
    {
      REQUIRE(solution.solve({1, 5, 10, 34, 112, 120}, 123) == 123);
    }
}