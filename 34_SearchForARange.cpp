//
//  34_SearchForARange.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 3/15/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { // time: O(logn); space: O(1)
        vector<int> res(2, -1); // if not found, return [-1, -1]
        if (nums.empty()) { // Invalid Input
            return res;
        }
        int n = (int) nums.size();
        int i = 0, j = n - 1;
        // Search for the left boundary
        while (i < j) {
            int mid = i + (j - i) / 2; // this equation is biased to the left
            if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid;
            }
        }
        if (nums[i] != target) { // if target is not found in the array
            return res;
        } else {
            res[0] = i;
        }
        j = n - 1; // reset j to the end of array
        // Search for the right boundary
        while (i < j) {
            int mid = i + (j - i + 1) / 2; // make it biased to the right
            if (nums[mid] > target) {
                j = mid - 1;
            } else {
                i = mid;
            }
        }
        res[1] = j;
        return res;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({5, 7, 7, 8, 8, 10});
    vector<int> res = solution.searchRange(nums, 8);
    for (int& i : res) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> nums1({});
    vector<int> res1 = solution.searchRange(nums1, 1);
    for (int& i : res1) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
