/*
Problem - 3: Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Constraints:
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = s.size(); // total size of string
        if(stringLength == 0) return 0;
        int maxSubstrLength = 1; // maximum length of substring so far found
        unordered_map<char, pair<int, int>> visited; // will store the visited characters for checking duplicates -> character: [round at which last updated, index]
        
        int round = 1;
        int currentLength = 0;
        int currentIndex = 0;
        pair<int, int> entry; // for storing [round, index] in each iteration
        while(true) {
            char ch = s.at(currentIndex);
            // if character is already visited
            if(visited.count(ch)) {
                entry = visited[ch];
                if(round == entry.first) {
                    // found in current round
                    maxSubstrLength = max(maxSubstrLength, currentLength);
                    currentLength = 0;
                    round++;
                    currentIndex = entry.second + 1;
                    // terminate loop if not enough elements to exceed maxLength so far
                    if(stringLength - currentIndex <= maxSubstrLength) {
                        break;
                    }
                }
                else {
                    // the character was found in any other previous rounds
                    entry = {round, currentIndex};
                    visited[ch] = entry;
                    currentLength++;
                    currentIndex++;
                }
            }
            else{
                // if character is not visited yet
                entry = {round, currentIndex};
                visited[ch] = entry;
                currentIndex++;
                currentLength++;
            }
            // terminate loop at end of string
            if(currentIndex >= stringLength) {
                maxSubstrLength = max(maxSubstrLength, currentLength);
                break;
            }
        }
        return maxSubstrLength;
    }
};

class OptimizedSolution {
public:
    int lengthOfLongestSubstring(string s) {
        int stringLength = s.size();
        int maxWindowLength = 0;
        int left = 0, right = 0;
        vector<int> visited(256, -1); // assuming ASCII charcters
        while(right < stringLength) {
            char ch = s[right];
            if(visited[ch] != -1) {
                left = max(left, visited[ch] + 1);
            }
            visited[ch] = right;
            maxWindowLength = max(maxWindowLength, right - left + 1);
            right++;
        }
        return maxWindowLength;
    }
};

int main() {
    Solution sln;
    string s;
    cin >> s;
    cout << sln.lengthOfLongestSubstring(s);
    return 0;
}