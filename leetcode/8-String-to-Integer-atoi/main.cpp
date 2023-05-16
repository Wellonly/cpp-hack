
#include <bits/stdc++.h>
#include <string>

#include "catch.hpp"

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
      s.erase(0, s.find_first_of("-0123456789"));
      s.erase(min(s.find_first_not_of("-0123456789"), s.length()),-1);
      cout << ":" << s << ":" << endl;
      return stoi(s, 0, 10);
    }
};

TEST_CASE("String to Integer (atoi)", "[tests]")
{
    Solution solution;

    SECTION("Sample Input 1")
    {
        REQUIRE(solution.myAtoi(" fdgs  123  ") == 123);
    }

    SECTION("Sample Input 2")
    {
        REQUIRE(solution.myAtoi(" .-123") == -123);
    }
}
