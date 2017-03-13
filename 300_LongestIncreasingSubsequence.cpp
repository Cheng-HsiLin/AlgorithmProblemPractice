//
//  300_LongestIncreasingSubsequence.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/13/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // DP Method
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) { // time: O(n^2); space: O(n)
//         if (nums.empty()) {
//             return 0;
//         }
//         int res = 1, n = nums.size();
//         vector<int> dp(n, 1); // the results ending at i
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             res = max(res, dp[i]);
//         }
//         return res;
//     }
// };

// Follow-Up: O(nlogn) Solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // time: O(nlogn); space: O(n)
        if (nums.empty()) {
            return 0;
        }
        vector<int> ends;
        ends.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > ends.back()) {
                ends.push_back(nums[i]);
            } else {
                int l = 0, r = ends.size() - 1;
                // Binary Search
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (ends[mid] < nums[i]) {
                        l = mid + 1;
                    } else {
                        r = mid;
                    }
                }
                ends[r] = nums[i];
            }
        }
        return ends.size();
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({10, 9, 2, 5, 3, 7, 101, 18});
    cout << solution.lengthOfLIS(nums) << endl;
    return 0;
}
