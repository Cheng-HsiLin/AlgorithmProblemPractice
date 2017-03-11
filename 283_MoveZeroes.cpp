//
//  283_MoveZeroes.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// // Two-Pass Two Pointers Method (Not Minimized Operations)
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) { // time: O(n); space: O(1)
//         // Validate Input
//         if (nums.empty()) {
//             return;
//         }
//         int j = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != 0) {
//                 nums[j++] = nums[i];
//             }
//         }
//         while (j < nums.size()) {
//             nums[j++] = 0;
//         }
//     }
// };

// One-Pass Swap Method (Optimized number of operations)
class Solution {
public:
    void moveZeroes(vector<int>& nums) { // time: O(n); space: O(1)
        if (nums.empty()) {
            return;
        }
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[j++], nums[i]);
            }
        }
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({0, 1, 0, 3, 12});
    solution.moveZeroes(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
