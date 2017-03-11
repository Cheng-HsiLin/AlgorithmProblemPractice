//
//  169_MajorityElement.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Moore Voting Method
class Solution {
public:
    int majorityElement(vector<int>& nums) { // time: O(n); space: O(1)
        int count = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                res = nums[i];
            } else {
                count += (res == nums[i]) ? 1 : -1;
            }
        }
        return res;
    }
};

// // Bit Manipulation Method
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) { // time: (n); space: O(1)
//         int n = nums.size(), res = 0;
//         for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
//             int bitCount = 0;
//             for (int j = 0; j < n; j++) {
//                 if (nums[j] & mask) {
//                     bitCount++;
//                 }
//                 if (bitCount > n / 2) {
//                     res |= mask;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };

// Test
int main () {
    Solution solution;
    vector<int> nums({1, 1, 2, 2, 2, 2, 3});
    cout << solution.majorityElement(nums) << endl;
    return 0;
}
