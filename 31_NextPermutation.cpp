//
//  31_NextPermutation.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/10/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) { // time: O(n); space: O(1)
        int k = -1; // largest position of non-descending element
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if (k == -1) { // the whole array is in descending order
            reverse(nums.begin(), nums.end());
            return;
        }
        int l = -1; // largest index of element larger than nums[k]
        for (int j = n - 1; j >= 0; j--) {
            if (nums[j] > nums[k]) {
                l = j;
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({1, 2, 3});
    solution.nextPermutation(nums);
    for (int& i : nums) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
