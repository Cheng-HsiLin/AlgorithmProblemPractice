//
//  41_FirstMissingPositive.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/31/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2-Pass Method
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { // time: O(n); space: O(1)
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Swap the numbers until the number at position i is correct
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // Find the first number which is not at the right position
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums1({1,2,0}), nums2({3,4,-1,1});
    cout << solution.firstMissingPositive(nums1) << endl; // 3
    cout << solution.firstMissingPositive(nums2) << endl; // 2
    cout << endl;
    return 0;
}
