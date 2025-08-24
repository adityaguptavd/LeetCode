/*
Problem - 7: Reverse Integer
Link: https://leetcode.com/problems/reverse-integer/
Constraints:
    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
    -2^31 <= x <= 2^31 - 1
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    inline bool isNotInRange(int num) {
        if(num < 0) return num < ((INT_MIN - (num % 10)) / 10);
        return num > ((INT_MAX - (num % 10)) / 10);
    }
public:
    int reverse(int x) {
        if(x > -10 && x < 10) return x;
        // int sign = x < 0; // 0 for positive and 1 for negative
        int reversed = 0;
        while(x != 0) {
            if(isNotInRange(reversed)) return 0;
            reversed = (reversed * 10) + (x % 10);
            x = x / 10;
        }
        return reversed;
    }
};

int main() {
    Solution sln;
    int x = -2147483412;
    cout << sln.reverse(x);
    return 0;
}