//
//  81_SearchInRotatedSortedArrayII.cpp
//  AlgorithmPractice
//
//  Created by Cheng-Hsi Lin on 4/03/17.
//  Copyright © 2017 Cheng-Hsi Lin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) { // time: O(n); space: O(1)
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else { // nums[left] == nums[mid]
                left++;
            }
        }
        return false;
    }
};

// Test
int main () {
    Solution solution;
    vector<int> nums({4,5,6,7,0,1,2});
    cout << (solution.search(nums, 2) ? "True" : "False") << endl;
    return 0;
}
