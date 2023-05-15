#include <string>
#include <vector>
#include <map>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

class Solution {
public:
    string solve(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        int n = int(s.size());
        int sections = ceil(n / (2 * numRows - 2.0));
        int numCols = sections * (numRows - 1);
        
        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
        
        int currRow = 0, currCol = 0;
        int currStringIndex = 0;
        
        // Iterate in zig-zag pattern on matrix and fill it with string characters.
        while (currStringIndex < n) {
            // Move down.
            while (currRow < numRows && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow++;
                currStringIndex++;
            }
            
            currRow -= 2;
            currCol++;
            
            // Move up (with moving right also).
            while (currRow > 0 && currCol < numCols && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }
        
        string answer;
        for (auto& row: matrix) {
            for (auto& character: row) {
                if (character != ' ') {
                    answer += character;
                }
            }
        }
        
        return answer;
    }
};

TEST_CASE("Zigzag Conversion", "[tests]")
{
    Solution solution;

    SECTION("LeetCode Sample Input 1")
    {
        REQUIRE(solution.solve("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    }

    SECTION("LeetCode Sample Input 2")
    {
        REQUIRE(solution.solve("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    }
}