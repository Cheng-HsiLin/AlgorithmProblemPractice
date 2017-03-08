//
//  268_MissingNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// // Math Formula Method
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) { // time: O(nums); space: O(1)
//         int n = nums.size();
//         int idealSum = n * (n + 1) / 2;
//         int realSum = 0;
//         for (int& num : nums) {
//             realSum += num;
//         }
//         return idealSum - realSum;
//     }
// };

// XOR Bit Manipulation Method (More Efficient)
class Solution {
public:
    int missingNumber(vector<int>& nums) { // time: O(nums); space: O(1)
        int res = 0, i = 1;
        for (int& num : nums) {
            res ^= num;
            res ^= i++;
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums = {0, 1, 3};
    cout << solution.missingNumber(nums) << endl;
    return 0;
}
