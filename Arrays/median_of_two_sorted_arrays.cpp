#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;

        // edge case
        if(m == 0) { // one array can be empty
            if(n % 2 == 0) return (nums2[n/2 - 1] + nums2[n/2]) / 2.0;
            return nums2[n/2];
        }

        int low = 0, high = m;
        int i = 0;
        int j = 0;
        while(low <= high) {
            i = (low + high) / 2;
            j = (total + 1) / 2 - i;

            int left1 = i == 0 ? INT_MIN : nums1[i-1];
            int right1 = i == m ? INT_MAX : nums1[i];

            int left2 = j == 0 ? INT_MIN : nums2[j-1];
            int right2 = j == n ? INT_MAX : nums2[j];

           if(left1 <= right2 && right1 >= left2) {
            if(total % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            return max(left1, left2);
           }
           if(left1 > right2) {
            high = i - 1;
           }
           else{
            low = i + 1;
           }
        }
        return 0.0;

    }
};

int main() {
    Solution s;
    vector<int> a = {1, 8};
    vector<int> b = {2, 7};
    cout << s.findMedianSortedArrays(a, b) << endl;
    return 0;
}