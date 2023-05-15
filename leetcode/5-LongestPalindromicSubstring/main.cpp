// A C++ solution for longest palindrome
 
#include <bits/stdc++.h>
using namespace std;
 
// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
 
// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
int longestPalindromeSubstr(string str)
{
    // Get length of input string
    int n = str.size();
 
    // All substrings of length 1 are palindromes
    int maxLength = 1, start = 0;
 
    // Nested loop to mark start and end index
    for (int i = 0; i < str.length(); i++) {
        for (int j = i; j < str.length(); j++) {
            int flag = 1; //1=found
 
            // Check palindrome
            for (int k = 0; (k < (j - i + 1) / 2) && flag; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;
 
            // Palindrome
            if (flag && (j - i + 1) > maxLength) {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }
 
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);
    return maxLength;
}
 
int main()
{
    string str = "abba"; //"abba":4
    cout << "\nLength is: " << longestPalindromeSubstr(str);
    return 0;
}