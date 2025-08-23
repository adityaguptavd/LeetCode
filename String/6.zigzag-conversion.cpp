/*
Problem - 6: Zigzag Conversion
Link: https://leetcode.com/problems/zigzag-conversion/
Constraints:
    1 <= s.length <= 1000
    s consists of English letters (lower-case and upper-case), ',' and '.'.
    1 <= numRows <= 1000
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int strLength = s.size();
        if(strLength <= 2 || numRows < 2) return s;
        string converted;
        converted.reserve(strLength);
        pair<int, int> skippableIndices = { -1, -1 };
        int minLength = min(numRows, strLength);
        for (int i = 1; i <= minLength; i++) {
            skippableIndices.first = 2 * (numRows - i);
            skippableIndices.second = (2 * i) - 2;
            converted.push_back(s[i-1]);
            int j = i-1;
            while (true) {
                if(skippableIndices.first > 0) {
                    j += skippableIndices.first;
                    if(j >= strLength) break;
                    converted.push_back(s[j]);
                }
                if(skippableIndices.second > 0) {
                    j += skippableIndices.second;
                    if(j >= strLength) break;
                    converted.push_back(s[j]);
                }
            }
        }
        return converted;
    }
};

class VectorApproachSolution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string result;
        for (string &row : rows) result += row;
        return result;
    }
};


int main() {
    Solution sln;
    cout << sln.convert("PAYPALISHIRING", 3);
    return 0;
}