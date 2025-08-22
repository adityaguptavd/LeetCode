/*
Problem - 14: Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/
Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = strs[0];
        size_t longestPrefixLength = strs[0].size();
        if(longestPrefix.empty()) return longestPrefix;
        size_t length = strs.size();
        for (size_t i = 1; i < length; i++) {
            if(strs[i].empty()) {
                longestPrefix = "";
                break;
            }
            size_t minStrLength = min(longestPrefixLength, strs[i].size());
            longestPrefix = longestPrefix.substr(0, minStrLength);
            for (size_t j = 0; j < minStrLength; j++) {
                if(longestPrefix[j] != strs[i][j]) {
                    longestPrefix = longestPrefix.substr(0, j);
                    longestPrefixLength = j;
                    break;
                }
            }
            if(longestPrefix.empty()) {
                break;
            }
            
        }
        return longestPrefix;        
    }
};

class OptimizedSolution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t longestPrefixLength = strs[0].size();
        if(!longestPrefixLength) return "";
        size_t vectorLength = strs.size();
        for (size_t i = 1; i < vectorLength; i++) {
            if(strs[i].empty()) return "";
            size_t minStringLength = min(longestPrefixLength, strs[i].size());
            longestPrefixLength = minStringLength;
            for (size_t j = 0; j < minStringLength; j++) {
                if(strs[i][j] != strs[0][j]) {
                    longestPrefixLength = j;
                    break;
                }
            }
            if(!longestPrefixLength) return "";
        }
        return strs[0].substr(0, longestPrefixLength);
    }
};

int main() {
    OptimizedSolution sln;
    vector<string> strs = {"ab", "a"};
    cout << sln.longestCommonPrefix(strs);
    return 0;
}