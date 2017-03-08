//
//  136_SingleNumber.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/07/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// XOR Bit Manipulation Method
class Solution {
public:
    int singleNumber(vector<int>& nums) { // time: O(n); space: O(1)
        for (int i = 1; i < nums.size(); i++) {
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4};
    cout << solution.singleNumber(nums) << endl;
    return 0;
}
