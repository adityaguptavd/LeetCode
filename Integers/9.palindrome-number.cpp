/*
Problem - 9: Palindrome Number
Link: https://leetcode.com/problems/palindrome-number/

Constraints:
    -231 <= x <= 231 - 1
    
Follow up: Could you solve it without converting the integer to a string?
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(long long x) {
        if(x < 0) return false;
        if(x < 10) return true;
        long long reverseNumber  = x % 10;
        long long temp = x;
        x  = x / 10;
        while(x != 0) {
            reverseNumber = (reverseNumber * 10) + (x % 10);
            x = x / 10;
        }
        return reverseNumber == temp;
    }
};

class OptimizedSolution {
public:
    bool isPalindrome(long long x) {
        // Negative numbers or numbers ending with 0 but not 0 itself are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        long long reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // If even number of digits, x == reversedHalf
        // If odd number of digits, x == reversedHalf/10 (ignore middle digit)
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};

int main() {
    Solution sln;
    int num;
    cin >> num;
    cout << sln.isPalindrome(num);
    return 0;
}