#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t size = nums.size();
        unordered_map<int, int> seenValues;
        int length = nums.size();
        int requiredValue = 0;
        for (int i = 0; i < length; i++)
        {
            requiredValue = target - nums.at(i);
            if(seenValues.count(requiredValue)) {
                return { seenValues[requiredValue], i };
            }
            seenValues[nums.at(i)] = i;
        }
        return {-1, -1};
    }
};

int main() {
    Solution sln;
    vector<int> nums = { 2, 9, 10, 7 };
    vector<int> indices = sln.twoSum(nums, 9);
    for (int ind: indices)
    {
        cout << ind << " ";
    }
    
    return 0;
}