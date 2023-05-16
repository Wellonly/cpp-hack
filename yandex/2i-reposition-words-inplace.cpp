#include <string>
#include <vector>
#include <map>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

class Solution {
public:
  void solve(string& s) {
    auto len = s.length();
    for (uint i = 0; i < len/2; i++) {
      char sv = s[i];
      s[i] = s[len-i-1];
      s[len-i-1] = sv;
    }
    uint pos = 0;
    while (pos < s.length()) {
      uint next = min(s.find(" ",pos), s.length())-1;
      if (next == string::npos) {pos++; continue;} //first(last) space skip
      size_t to = pos+(next-pos+1)/2;
      for (uint i = pos; i < to; i++) {
        char sv = s[i];
        s[i] = s[pos+next-i];
        s[pos+next-i] = sv;
      }
      pos = next+2;
    }
  }
};


TEST_CASE("Reposition words", "[tests]")
{
    Solution solution;
    string test;
    SECTION("Sample Input 1")
    {
        test = "quick brown fox";
        solution.solve(test);
        REQUIRE(test == "fox brown quick");
    }

    SECTION("Sample Input 2")
    {
        test = "hello every body there ";
        solution.solve(test);
        REQUIRE(test == " there body every hello");
    }
}
