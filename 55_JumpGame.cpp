//
//  55_JumpGame.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/22/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Greedy Method based on the max position reached
class Solution {
public:
    bool canJump(vector<int>& nums) { // time: O(n); space: O(1)
        if (nums.empty() == true) {
            return false;
        }
        int n = nums.size();
        int maxReach = 0;
        for (int i = 0; i <= maxReach; i++) {
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true;
            }
        }
        return false;
    }
};

// // Greedy Method based on the steps left
// class Solution {
// public:
//     bool canJump(vector<int>& nums) { // time: O(n); space: O(1)
//         if (nums.empty() == true) {
//             return false;
//         }
//         int n = nums.size();
//         int step = nums[0];
//         for (int i = 1; i < n; i++) {
//             if (--step < 0) {
//                 return false;
//             }
//             step = max(step, nums[i]);
//         }
//         return true;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums1({2,3,1,1,4}), nums2({3,2,1,0,4});
    cout << (solution.canJump(nums1) ? "True" : "Fasle") << endl;
    cout << (solution.canJump(nums2) ? "True" : "Fasle") << endl;
    return 0;
}
