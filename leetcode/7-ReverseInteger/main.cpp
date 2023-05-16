#include <bits/stdc++.h>

#include "catch.hpp"

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev >= INT_MAX/10 && pop > 7) return 0;
            if (rev <= INT_MIN/10 && pop < -8) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

TEST_CASE("ReverseInteger", "[tests]")
{
    Solution solution;

    SECTION("LeetCode Sample Input 1")
    {
        REQUIRE(solution.reverse(123) == 321);
    }

    SECTION("LeetCode Sample Input 2")
    {
        REQUIRE(solution.reverse(-123) == -321);
    }
}