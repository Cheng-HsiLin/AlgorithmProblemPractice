//
//  198_HouseRobber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/15/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) { // time: O(n); space: O(1)
//         int prevNotRobbed   = 0;
//         int prevRobbed      = 0;
//         for (int& num : nums) {
//             int tmp = prevNotRobbed;
//             // Not rob the current house
//             prevNotRobbed   = max(prevNotRobbed, prevRobbed);
//             // Rob the current house
//             prevRobbed      = tmp + num;
//         }
//         return max(prevNotRobbed, prevRobbed);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) { // time: O(n); space: O(1)
        int n = nums.size(), pre = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            int tmp = max(pre + nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({1,3,5,6,7,3,2});
    cout << solution.rob(nums1) << endl;
    vector<int> nums2({3,5,6,7,8,3,2,1});
    cout << solution.rob(nums2) << endl;
    return 0;
}
