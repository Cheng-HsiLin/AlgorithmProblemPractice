//
//  152_MaximumProductSubarray.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/18/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) { // time: O(n); space: O(1)
        // Validate Input
        if (nums.empty() == true) {
            return 0;
        }
        int res = nums[0], curMin = nums[0], curMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(curMin, curMax);
            }
            curMax = max(curMax * nums[i], nums[i]);
            curMin = min(curMin * nums[i], nums[i]);
            res = max(res, curMax);
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({2, 3, -2, 4}); // 6
    cout << solution.maxProduct(nums) << endl;
    return 0;
}
