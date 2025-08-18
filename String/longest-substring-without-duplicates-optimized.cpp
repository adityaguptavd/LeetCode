// Sliding window approach
#include<bits/stdc++.h>

using namespace std;

class Solution {
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