//
//  80_RemoveDuplicatesFromSortedArrayII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { // time: O(n); space: O(1)
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int pos = 2;
        for (int i = 2; i < n; i++) {
            if (nums[pos - 2] != nums[i]) {
                nums[pos++] = nums[i];
            }
        }
        return pos;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1,1,1,2,2,3});
    cout << solution.removeDuplicates(nums) << endl; // 1 1 2 2 3
    return 0;
}
