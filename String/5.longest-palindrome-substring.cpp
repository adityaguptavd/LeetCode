/*
Problem - 5: Longest Palindromic Substring
Link: https://leetcode.com/problems/longest-palindromic-substring/

Constraints:
    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/

#include<bits/stdc++.h>

using namespace std;

// expand-around-center approach
class Solution {
public:
    string longestPalindrome(string s) {
        int strLength = (int)s.size();
        // if string is empty or has single character, string is palindrome
        if(strLength < 2) return s;
        
        int start = 0, maxSubstrLength = 1;

        // lambda function to check palindrome
        auto expand = [&](int left, int right) {
            while(left >= 0 && right < strLength && s[left] == s[right]) {
                left--; right++;
            }
            if(right - left - 1 > maxSubstrLength) {
                start = left + 1;
                maxSubstrLength = right - left - 1;
            }
        };

        for (int i = 0; i < strLength; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxSubstrLength);
    }
};

int main() {
    Solution sln;
    cout << sln.longestPalindrome("babad");
    return 0;
}