//
//  53_MaximumSubarray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// O(n) Solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) { // time: O(n); space: O(1)
        int sum = 0, res = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return res;
    }
};

// // Divide And Conquer Method (More Stable)
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) { // time: O(nlogn); space: O(logn)
//         if (nums.empty()) {
//             return 0;
//         }
//         int n = nums.size();
//         return helper(nums, 0, n - 1);
//     }
// private:
//     int helper(vector<int>& nums, int left, int right) {
//         if (left > right) {
//             return INT_MIN;
//         }
//         int mid = left + (right - left) / 2;
//         int leftAns = helper(nums, left, mid - 1), rightAns = helper(nums, mid + 1, right);
//         int leftMax = 0, rightMax = 0, sum = 0;
//         // Find max @ [left, mid - 1]
//         for (int i = mid - 1; i >= left; i--) {
//             sum += nums[i];
//             leftMax = max(leftMax, sum);
//         }
//         sum = 0; // reset to 0
//         // Find max @ [mid + 1, right]
//         for (int j = mid + 1; j <= right; j++) {
//             sum += nums[j];
//             rightMax = max(rightMax, sum);
//         }
//         return max(max(leftAns, rightAns), leftMax + nums[mid] + rightMax);
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({-2,1,-3,4,-1,2,1,-5,4}); // [4,-1,2,1] => 6
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}
