/*
Problem - 13: Roman to Integer
Link: https://leetcode.com/problems/roman-to-integer/

Constraints:
    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
    int getIntValue(char romanChar) {
        switch(romanChar) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        size_t length = s.size();
        int number = 0;
        for (size_t i = 0; i < length; i++) {
            if(i + 1 < length && getIntValue(s[i]) < getIntValue(s[i + 1])) {
                number -= getIntValue(s[i]);
            }
            else{
                number += getIntValue(s[i]);
            }
        }
        return number;
    }
};

int main() {
    Solution sln;
    string s;
    while(true) {
        cout << "Enter roman number (type 'exit' to quit): ";
        cin >> s;
        if(s == "exit") break;
        cout << sln.romanToInt(s) << endl;
    }
    return 0;
}