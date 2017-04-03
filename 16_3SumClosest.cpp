//
//  16_3SumClosest.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) { // time: O(n^2); space: O(1)
        int n = nums.size();
        if (n < 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        // Sort the numbers for the two pointers method
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (abs(tmp - target) < abs(res - target)) {
                    res = tmp;
                    // find the target, distance = 0, return directly
                    if (res == target) {
                        return res;
                    }
                }
                tmp > target ? k-- : j++;
            }
        }
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({-1,2,1,-4});
    cout << solution.threeSumClosest(nums, 1) << endl; // -1 + 2 + 1 = 2
    return 0;
}
