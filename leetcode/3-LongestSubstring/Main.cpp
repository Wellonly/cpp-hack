#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        set<char> chars;
        int startIdx = 0;
        int endIdx = 0;
        int maxLength = 0;

        // O(n) approach:
        // Expand end from start until we reach a duplicated character, then bring start towards end... like a slinky :)
        int length = s.size();
        while (startIdx < length && endIdx < length)
        {
            char c = s[endIdx];
            if (chars.find(c) != chars.end())
            {
                chars.erase(s[startIdx]);
                startIdx++;
            }
            else
            {
                chars.insert(c);
                endIdx++;
            }

            maxLength = max(maxLength, endIdx - startIdx);
        }

        return maxLength;
    }
};

TEST_CASE("LongestSubstring", "[tests]")
{
    Solution solution;

    REQUIRE(solution.lengthOfLongestSubstring("abcabcbb") == 3);
    REQUIRE(solution.lengthOfLongestSubstring("bbbbb") == 1);
    REQUIRE(solution.lengthOfLongestSubstring("pwwkew") == 3);
    REQUIRE(solution.lengthOfLongestSubstring("") == 0);
    REQUIRE(solution.lengthOfLongestSubstring("a") == 1);
    REQUIRE(solution.lengthOfLongestSubstring("ab") == 2);
    REQUIRE(solution.lengthOfLongestSubstring("abab") == 2);
    REQUIRE(solution.lengthOfLongestSubstring("dvdf") == 3);
}